#include "myfunctions.h"
#include "itemhandler.h"
#include <QDebug>

int MyFunctions::poslet = -1;
QStringList MyFunctions::letters = {};
MyFunctions::MyFunctions(QObject *parent)
    : QAbstractItemModel(parent)
{
}
QString MyFunctions:: intToStr(int number) {
    QString numberStr = QString::number(number);

    if (numberStr.length() != 9)
        return QString();

    QChar firstDigit = numberStr.at(0);
    QString temp = "";
    temp.append(firstDigit);
    if(deviceFromSN(temp)!=""){
    numberStr[0] = deviceFromSN(temp).at(0);}
//    if(deviceFromSN(temp).size()!=1){qDebug() << "something wrong with deviceFromSN";}


    int fourthDigit = numberStr.mid(3, 1).toInt();
    int fifthDigit = numberStr.mid(4, 1).toInt();
    int combined = fourthDigit * 10 + fifthDigit;

    if (combined >= 1 && combined <= 26) {
        QChar letter = QChar('A' + combined - 1);
        numberStr.replace(3, 2, letter);
    }

    return numberStr;
}

QString MyFunctions::reverseSN(const QString &input) {
    QString result = input;

    if (!result.isEmpty()) {
        QChar firstLetter = result.at(0).toUpper();
        result[0] = QString::number(snLetter(firstLetter)).at(0);
//        if (firstLetter.toUpper() == 'B') {
//            result[0] = '1';
//        } else if (firstLetter.toUpper() == 'N') {
//            result[0] = '2';
//        } else if (firstLetter.toUpper() == 'S') {
//            result[0] = '3';
//        }
    }

    if (result.length() > 3) {
        QChar secondLetter = result.at(3).toUpper();
        if (secondLetter.isLetter()) {
            int positionInAlphabet = secondLetter.toLatin1() - 'A' + 1;
            if (positionInAlphabet >= 1 && positionInAlphabet <= 26) {
                QString positionString = QString::number(positionInAlphabet).rightJustified(2, '0');
                result.replace(3, 1, positionString);
            }
        }
    }

//    qDebug() << "reverseSN result:" << result;
    return result;
}

QString MyFunctions::smallSN(QString input) {
    QString result="";
    bool letter=1;
    if(!input.isEmpty()){
        for(int i=0;i<input.length();i++){
            if(letter&&(input.at(i).isLetter())){
//                qDebug()<<i <<"time";
                input = input.toUpper();
                int positionInAlphabet = input.at(i).toLatin1() - 'A' + 1;
                if (positionInAlphabet >= 1 && positionInAlphabet <= 26) {
                    QString positionString = QString::number(positionInAlphabet).rightJustified(2, '0');
                    result.append(positionString);
//                    qDebug() <<"positionstring isssss: "<<positionString;
                }
                poslet = i;
            }
            else{
                result.append(input.at(i));
//                qDebug()<< "what?!";
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

int MyFunctions :: binaryToDecimal(const QString& binary) {

    int decimal = 0;
    int power = 1;
    for (int i = binary.length() - 1; i >= 0; --i) {
        int bit = binary.at(i).digitValue();

        decimal += bit * power;

        power *= 2;
    }

    return decimal;
}

QString MyFunctions :: decimalToBinary(int decimal) {
    QString binary = "";

    while (decimal > 0 || binary.length() < 14) {
        binary.prepend(QString::number(decimal % 2));

        decimal /= 2;
    }

    while (binary.length() < 14) {
        binary.prepend('0');
    }

    return binary;
}
bool MyFunctions :: checkSN(QString sn){
    bool result = true;
    sn=sn.toUpper();
    if (sn==""){return false;}
    else{
        if (sn.length()==8){
            if(sn.at(0)=="B"||sn.at(0)=="S"||sn.at(0)=="N"){
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
        if(searchText.at(0).toUpper()=="B"||searchText.at(0).toUpper()=="S"||searchText.at(0).toUpper()=="N"){res = "SELECT "+column+" FROM "+tableName+" WHERE "+searchParam+" LIKE '"+MyFunctions::reverseSN( searchText)+"%' OR "+searchParam+" LIKE '___"+MyFunctions ::smallSN(searchText)+"%'";}
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
QString MyFunctions::deviceFromSN(QString SN) {
    try {
        if (letters.isEmpty()) {
//            qDebug() << "letters is empty, setting letters...";
            MyFunctions::setLetters();
        }

        // Validate SN here
        bool ok;
        int index = SN.toInt(&ok) - 1;
//        qDebug() << "letters :" << letters;

        if (!ok || index < 0 || letters.isEmpty()) {
            // Handle invalid SN
//            qDebug() << "invalid SN:" << SN;
            return QString();
        }

        return letters[(index * 2) + 1];
    } catch (const std::exception& e) {
        qDebug() << "Exception caught:" << e.what();
    }

    return QString(); // Or return an appropriate value
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
//    qDebug() << "Letters set: " << letters;
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
