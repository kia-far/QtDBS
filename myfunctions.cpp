#include "myfunctions.h"
#include "itemhandler.h"
#include <QDebug>
#include <QApplication>
#include <QFile>
#include <QSqlQuery>
#include <DatabaseConnection.h>
#include <QString>
#include <QLocale>

int MyFunctions::poslet = -1;
QStringList MyFunctions::letters = {};
MyFunctions::MyFunctions(QObject *parent)
    : QAbstractItemModel(parent)
{
}
QString MyFunctions::intToStr(unsigned int number) {
    QString numberStr = QString::number(number).rightJustified(10, '0'); // Ensure it's a 10-digit string

    if (numberStr.length() != 10)
        return QString(); // Return empty string if format is incorrect

    QString result;

    // First letter (from YY)
    int firstLetterPos = numberStr.mid(0, 2).toInt();
    if (firstLetterPos >= 11 && firstLetterPos <= 36) {  // Change range to 11-36
        QChar firstLetter = QChar('A' + firstLetterPos - 11);  // Adjust position by 11
        result.append(firstLetter);
    } else {
        return QString(); // Return empty string if position is invalid
    }

    // Next two digits (xx)
    result.append(numberStr.mid(2, 2)); // Digits remain unchanged

    // Second letter (from YY)
    int secondLetterPos = numberStr.mid(4, 2).toInt();
    if (secondLetterPos >= 11 && secondLetterPos <= 36) {  // Change range to 11-36
        QChar secondLetter = QChar('A' + secondLetterPos - 11);  // Adjust position by 11
        result.append(secondLetter);
    } else {
        return QString(); // Return empty string if position is invalid
    }

    // Last four digits (xxxx)
    result.append(numberStr.mid(6, 4)); // Digits remain unchanged

    return result;
}


QString MyFunctions::reverseSN(const QString &input) {
    if (input.length() != 8)
        return QString(); // Return empty string if format is incorrect

    QString result;

    // First Letter (XX)
    QChar firstLetter = input.at(0).toUpper();
    int firstLetterPos = firstLetter.toLatin1() - 'A' + 11;  // Adjust position by 11
    result.append(QString::number(firstLetterPos).rightJustified(2, '0')); // Append 2-digit position

    // Next two digits (xx)
    result.append(input.mid(1, 2)); // Append the next two digits as-is

    // Second Letter (YY)
    QChar secondLetter = input.at(3).toUpper();
    int secondLetterPos = secondLetter.toLatin1() - 'A' + 11;  // Adjust position by 11
    result.append(QString::number(secondLetterPos).rightJustified(2, '0')); // Append 2-digit position

    // Remaining 4 digits (xxxx)
    result.append(input.mid(4, 4)); // Append the remaining digits as-is

    // Remove leading zero if necessary
    if (result.at(0) == '0') {
        result.remove(0, 1);
    }

    return result;
}


QString MyFunctions::newReverseSN(const QString &input) {
    QString result;

    for (int i = 0; i < input.length(); ++i) {
        QChar currentChar = input.at(i);

        // Check if the character is a letter
        if (currentChar.isLetter()) {
            // Convert letter to its position in the alphabet (A = 11, B = 12, ..., Z = 36)
            int letterPos = currentChar.toUpper().toLatin1() - 'A' + 11;  // Adjust position by 11
            result.append(QString::number(letterPos).rightJustified(2, '0')); // Append 2-digit position
        }
        // Check if the character is a digit
        else if (currentChar.isDigit()) {
            result.append(currentChar); // Append digit as-is
        }
    }

    // Remove leading zero if it exists
    if (!result.isEmpty() && result.at(0) == '0') {
        result.remove(0, 1);
    }

    return result;
}

QString MyFunctions::smallSN(QString input) {
    QString result="";
    bool letter = true;
    poslet = -1;
    if (!input.isEmpty()) {
        for (int i = 0; i < input.length(); i++) {
            if (letter && input.at(i).isLetter()) {
                input = input.toUpper();
                int positionInAlphabet = input.at(i).toLatin1() - 'A' + 11;  // Adjust position by 11
                if (positionInAlphabet >= 11 && positionInAlphabet <= 36) {  // Ensure the range is 11-36
                    QString positionString = QString::number(positionInAlphabet).rightJustified(2, '0');
                    result.append(positionString);
                }
                poslet = i;
            } else {
                result.append(input.at(i));  // Append digits unchanged
            }
        }
    }

    return result;
}

QString MyFunctions::querySolver(){
    QString res="";
    if(!(poslet==-1)){
        for (int i=0;i<4-poslet;i++){
            res.append("_");

        }
    }
    else{res="-1";}
//    qDebug()<< res<< "hello"<<poslet;
    poslet =-1;
    return res;
}

// int MyFunctions :: binaryToDecimal(const QString& binary) {

//     int decimal = 0;
//     int power = 1;
//     for (int i = binary.length() - 1; i >= 0; --i) {
//         int bit = binary.at(i).digitValue();

//         decimal += bit * power;

//         power *= 2;
//     }

//     return decimal;
// }

// QString MyFunctions :: decimalToBinary(int decimal) {
//     QString binary = "";

//     while (decimal > 0 || binary.length() < 14) {
//         binary.prepend(QString::number(decimal % 2));

//         decimal /= 2;
//     }

//     while (binary.length() < 14) {
//         binary.prepend('0');
//     }

//     return binary;
// }

bool MyFunctions :: checkSN(QString sn){
    setLetters();
    bool result = true;
    sn=sn.toUpper();
    if (sn==""){return false;}
    else{
        if (sn.length()==8){
            if(letters.contains(sn.at(0))){
                if(sn.at(3).isLetter()){
                    for (int i = 1;i<3;i++){
                        if (!sn.at(i).isDigit()){result = false;}
                    }
                    for (int i = 1;i<5;i++){
                        if(!sn.at(i+3).isDigit()){result = false;}
                    }
                }
                else {result = false;}
            }
            else{result=false;}
        }
        else{result = false;}
    }
    return result;
}

int MyFunctions::snLetter(QString letter){
    int index =1;
    QStringList letters = ItemHandler::readLetters();
    for (int i=0;i<letters.size();i++){
        if(letter == letters[i]){return index;}
        index++;
    }
    return 0;
}

QString MyFunctions::searchHandler(QString column,QString tableName, QString searchParam ,QString searchText){
    QString res;
    QString context;
    QString space = "";
    // qDebug() << searchText<<"this is searchText";
    // qDebug () << newReverseSN(searchText)<<"this is the NRS";
    setLetters();
    searchText = searchText.toUpper();
    if (searchText==""){res = "SELECT "+column+" FROM "+tableName+" WHERE "+searchParam+" LIKE '%"+searchText+"%'";}
    else{
        if(searchText.at(0).isLetter()){
            if( letters.contains( searchText.at(0))){
                res = "SELECT "+ column +" FROM "+tableName+" WHERE ("+searchParam + " LIKE '"+MyFunctions::newReverseSN( searchText)+"%') OR ("+searchParam + " LIKE '____" +MyFunctions::newReverseSN(searchText)+"%')";
            }
            else{
                res = "SELECT "+ column +" FROM "+tableName+" WHERE ("+searchParam + " LIKE '____" +MyFunctions::newReverseSN(searchText)+"%')";

            }
        }
        else{
            context = MyFunctions::smallSN(searchText);
            space = MyFunctions::querySolver();
            if(!(space=="-1")){res = "SELECT "+column+" FROM "+tableName+" WHERE "+searchParam+" LIKE '"+space+context+"%'";
            /*qDebug()<<"LIKE debug try '"+space+context+"%'";*/}
            else{
                res = "SELECT "+column+" FROM "+tableName+" WHERE (("+searchParam+" LIKE '__%"+context+"%______') OR ("+searchParam+" LIKE '______%"+context+"%'))";
//                                    qDebug()<<"LIKE debug try '"+space+context+"%'";
            }
        }


    }

    return res;
}


bool MyFunctions::deviceFromLetter(QString SN,QString device) {

    if (letters.isEmpty()) {
        setLetters();
    }

    if(letters.contains(SN.at(0).toUpper())){

        for(int i=0;i<letters.size();i++){
            if(letters[i]==SN.at(0).toUpper()){
                for(int j=i;j>-1;j--){
                    if(letters[j].length()==1){}
                    else{
                        if(letters[j]==device){return true;}
                        else{j=0;}
                    }
                }
            }
        }
    }
    else{return false;}


    return false;
}

void MyFunctions::setLetters() {
    letters.clear();  // Ensure the list is reset

    QStringList nameLetters = ItemHandler::nameLetter();

    if (nameLetters.isEmpty()) {
        return;
    }

    for (int i = 0; i < nameLetters.size(); i++) {
        letters.append(nameLetters[i]);
    }


}

bool MyFunctions::enterAdminMode(){
    QString jsonPath;
    QString adr = qApp->applicationDirPath();
    QString jsonPathFile = adr + "/JSONPath";

    // Open the file that contains the path to the JSON
    QFile file(jsonPathFile);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        jsonPath = in.readLine().trimmed();  // Read and trim the database path from the file
        file.close();

        if (jsonPath.isEmpty()) {
            qDebug() << "Database path file is empty!";
            return false;
        }
    } else {
        qDebug() << "Failed to open database path file:" << file.errorString();
        return false;
    }

    // Now, open and read the AdminActive file
    QString adminModeFile = jsonPath + "/AdminActive";  // Ensure proper path format
    QFile adminFile(adminModeFile);

    qDebug() << "AdminActive file path:" << adminModeFile;  // Debugging path

    if (adminFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream adminIn(&adminFile);
        QString value = adminIn.readLine().trimmed();  // Read and trim the content of AdminActive file
        adminFile.close();

        qDebug() << "AdminActive value read:" << value;  // Debugging value

        // Check the value of AdminActive
        if (value == "1") {
            return false;  // Admin mode is active
        } else if (value == "0") {
            return true;   // Admin mode is not active
        } else {
            qDebug() << "Invalid value in AdminActive file!";
            return false;
        }
    } else {
        qDebug() << "Failed to open AdminActive file:" << adminFile.errorString();
        return false;
    }
}



bool MyFunctions::setAdminMode(bool isActive) {
    QString jsonPath;
    QString adr = qApp->applicationDirPath();
    QString jsonPathFile = adr + "/JSONPath";

    // Open the file that contains the path to the JSON
    QFile file(jsonPathFile);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        jsonPath = in.readLine();  // Read the database path from the file
        file.close();

        if (jsonPath.isEmpty()) {
            qDebug() << "Database path file is empty!";
            return false;
        }
    } else {
        qDebug() << "Failed to open database path file:" << file.errorString();
        return false;
    }

    // Now, open and write to the AdminActive file
    QString adminModeFile = jsonPath + "/AdminActive";
    QFile adminFile(adminModeFile);

    if (adminFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream adminOut(&adminFile);

        // Write "1" if admin mode is active, otherwise write "0"
        if (isActive) {
            adminOut << "1";
        } else {
            adminOut << "0";
        }

        adminFile.close();
        return true;  // Successfully wrote the value
    } else {
        qDebug() << "Failed to open AdminActive file for writing:" << adminFile.errorString();
        return false;
    }
}

bool MyFunctions::checkData(QString data,QString column, QString table){
    QStringList devices = ItemHandler::loadDevices();
    DatabaseConnection& dbConnection = DatabaseConnection::getInstance();
    QSqlQuery query(dbConnection.getConnection());

    QStringList res;

    query.prepare("SELECT "+ column +" FROM "+ table +" WHERE "+ column +" LIKE :halfText");
    query.bindValue(":halfText", data);  // Use wildcards for partial match

    // Execute the query
    if (query.exec()) {
        //        qDebug() << "Fetch the results";
        while (query.next()) {
            res << query.value(0).toString();  // Assuming 'name' is the first column
        }
    } else {
        qDebug() << "Query execution failed:" << query.lastError().text();
    }

    return res.length();
}


int MyFunctions::convertToEnglishInt(const QString& localizedNumber) {
    // Use QLocale to parse the localized number (Persian in this case)
    QLocale persianLocale(QLocale::Persian);

    bool ok;
    int number = persianLocale.toInt(localizedNumber, &ok);

    if (!ok) {
        // Handle the case if the input is not a valid integer
        qDebug() << "Conversion failed. Input might not be a valid Persian number.";
        return -1; // or another indicator for failure
    }

    return number;
}


QString MyFunctions::convertToEnglishString(const QString& localizedString) {
    QString englishString;
    for (QChar ch : localizedString) {
        if (ch >= QChar(0x06F0) && ch <= QChar(0x06F9)) {
            // Convert Persian numeral to English numeral
            englishString += QChar(ch.unicode() - 0x06F0 + '0');
        } else {
            // Leave English characters and other symbols unchanged
            englishString += ch;
        }
    }
    // qDebug()<< "englishstring of :" << localizedString <<" is : "<<englishString;
    return englishString;
}
