#include "myfunctions.h"
#include "itemhandler.h"
#include <QDebug>

int MyFunctions::poslet = -1;
QStringList MyFunctions::letters = {};
MyFunctions::MyFunctions(QObject *parent)
    : QAbstractItemModel(parent)
{
}
QString MyFunctions::intToStr(int number) {
    QString numberStr = QString::number(number).rightJustified(10, '0'); // Ensure it's a 9-digit string

    if (numberStr.length() != 10)
        return QString(); // Return empty string if format is incorrect

    QString result;

    // First letter (from YY)
    int firstLetterPos = numberStr.mid(0, 2).toInt();
    if (firstLetterPos >= 1 && firstLetterPos <= 26) {
        QChar firstLetter = QChar('A' + firstLetterPos - 1);
        result.append(firstLetter);
    } else {
        return QString(); // Return empty string if position is invalid
    }

    // Next two digits (xx)
    result.append(numberStr.mid(2, 2));

    // Second letter (from YY)
    int secondLetterPos = numberStr.mid(4, 2).toInt();
    if (secondLetterPos >= 1 && secondLetterPos <= 26) {
        QChar secondLetter = QChar('A' + secondLetterPos - 1);
        result.append(secondLetter);
    } else {
        return QString(); // Return empty string if position is invalid
    }

    // Last four digits (xxxx)
    result.append(numberStr.mid(6, 4));

    return result;
}


QString MyFunctions::reverseSN(const QString &input) {
    if (input.length() != 8)
        return QString(); // Return empty string if format is incorrect

    QString result;

    // First Letter (XX)
    QChar firstLetter = input.at(0).toUpper();
    int firstLetterPos = firstLetter.toLatin1() - 'A' + 1;
    result.append(QString::number(firstLetterPos).rightJustified(2, '0')); // Append 2-digit position

    // Next two digits (xx)
    result.append(input.mid(1, 2)); // Append the next two digits as-is

    // Second Letter (YY)
    QChar secondLetter = input.at(3).toUpper();
    int secondLetterPos = secondLetter.toLatin1() - 'A' + 1;
    result.append(QString::number(secondLetterPos).rightJustified(2, '0')); // Append 2-digit position

    // Remaining 4 digits (xxxx)
    result.append(input.mid(4, 4)); // Append the remaining digits as-is
    if(result.at(0) == '0'){
        result.remove(0,1);
    }
    return result;
}

QString MyFunctions::newReverseSN(const QString &input) {
    QString result;

    for (int i = 0; i < input.length(); ++i) {
        QChar currentChar = input.at(i);

        // Check if the character is a letter
        if (currentChar.isLetter()) {
            // Convert letter to its position in the alphabet (A = 1, B = 2, ..., Z = 26)
            int letterPos = currentChar.toUpper().toLatin1() - 'A' + 1;
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
    bool letter=1;
    if(!input.isEmpty()){
        for(int i=0;i<input.length();i++){
            if(letter&&(input.at(i).isLetter())){
                input = input.toUpper();
                int positionInAlphabet = input.at(i).toLatin1() - 'A' + 1;
                if (positionInAlphabet >= 1 && positionInAlphabet <= 26) {
                    QString positionString = QString::number(positionInAlphabet).rightJustified(2, '0');
                    result.append(positionString);
                }
                poslet = i;
            }
            else{
                result.append(input.at(i));
            }
        }

    }
//    qDebug()<<"this is inside smallsn func"<<result;
            return result;
}
QString MyFunctions::querySolver(){
    QString res="";
    if(!(poslet==-1)){
        for (int i=0;i<3-poslet;i++){
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
    QString space;
    if (searchText==""){res = "SELECT "+column+" FROM "+tableName+" WHERE "+searchParam+" LIKE '%"+searchText+"%'";}
    else{
        if(letters.contains(searchText.at(0))){res = "SELECT "+column+" FROM "+tableName+" WHERE "+searchParam+" LIKE '"+MyFunctions::reverseSN( searchText)+"%' OR "+searchParam+" LIKE '___"+MyFunctions ::smallSN(searchText)+"%'";}
        else{
            context = MyFunctions::smallSN(searchText);
            space = MyFunctions::querySolver();
            if(!(space=="-1")){res = "SELECT "+column+" FROM "+tableName+" WHERE "+searchParam+" LIKE '"+space+context+"%'";
            /*qDebug()<<"LIKE debug try '"+space+context+"%'";*/}
            else{
                res = "SELECT "+column+" FROM "+tableName+" WHERE (("+searchParam+" LIKE '_%"+context+"%______') OR ("+searchParam+" LIKE '_____%"+context+"%'))";
//                                    qDebug()<<"LIKE debug try '"+space+context+"%'";
            }
        }
    }
    return res;
}
// QString MyFunctions::deviceFromSN(QString SN) {
//     try {
//         if (letters.isEmpty()) {
// //            qDebug() << "letters is empty, setting letters...";
//             MyFunctions::setLetters();
//         }

//         // Validate SN here
//         bool ok;
//         int index = SN.toInt(&ok) - 1;
// //        qDebug() << "letters :" << letters;

//         if (!ok || index < 0 || letters.isEmpty()) {
//             // Handle invalid SN
// //            qDebug() << "invalid SN:" << SN;
//             return QString();
//         }

//         return letters[(index * 2) + 1];
//     } catch (const std::exception& e) {
//         qDebug() << "Exception caught:" << e.what();
//     }

//     return QString(); // Or return an appropriate value
// }

bool MyFunctions::deviceFromLetter(QString SN,QString device) {

    if (letters.isEmpty()) {
        //            qDebug() << "letters is empty, setting letters...";
        setLetters();
    }
    // for(int i=0;i<letters.size()/2;i++){
    // if(SN.at(0).toUpper() == letters[2*i+1]){
    //         return letters[2*i];
    // }
    // }
    if(letters.contains(SN.at(0).toUpper())){
        qDebug() << "letters does include SN.at(0)";
    // bool check=true;
        for(int i=0;i<letters.size();i++){
            if(letters[i]==SN.at(0).toUpper()){
                for(int j=i;j>-1;j--){
                    if(letters[j].length()==1){/*qDebug()<<"jumped! also length of BN"<<letters[0].length();*/}
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
//    qDebug() << "Setting letters from ItemHandler::nameLetter()...";
    letters.clear();  // Ensure the list is reset

    QStringList nameLetters = ItemHandler::nameLetter();

    if (nameLetters.isEmpty()) {
//        qDebug() << "Warning: ItemHandler::nameLetter() is empty!";
        return;
    }

    for (int i = 0; i < nameLetters.size(); i++) {
        letters.append(nameLetters[i]);
    }

//    isDataReady = true;  // Mark data as ready
//    emit dataReady();  // Notify that data is ready
   // qDebug() << "Letters set: " << letters;
}



//QStringList MyFunctions::getLetters(){
//    if(letters.size()!=0){
//    return letters;}
//    else {
//        letters = ItemHandler::nameLetter();
//        return letters;
//    }
//}
//void MyFunctions::initializeData() {
//    // Start loading data
//    qDebug() << "Loading data from JSON file...";
//    MyFunctions::setLetters();

//    if (!letters.isEmpty()) {
////        isDataReady = true;  // Mark data as ready
//        qDebug() << "Data successfully loaded at startup!";
//    } else {
//        qDebug() << "Data loading failed or is still empty!";
//    }
//}
