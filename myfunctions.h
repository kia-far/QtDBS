#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

#include <QAbstractItemModel>

class MyFunctions : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit MyFunctions(QObject *parent = nullptr);
    static QString intToStr(int number);
    static QString reverseSN(const QString &input);
    static int binaryToDecimal(const QString& binary);
    static QString decimalToBinary(int decimal);
    static QString smallSN(QString a);
    static bool checkSN(QString sn);
    static QString querySolver();
    static int snLetter(QString letter);
    static QString searchHandler(QString column,QString tableName, QString searchParam ,QString searchText);
    static QString deviceFromSN(QString SN);
    static QString deviceFromLetter(QString SN);
    static void setLetters();
    static QStringList getLetters();
//    static void initializeData();
signals:
    void dataReady();
private:
   static int poslet;
   static QStringList letters;
};

#endif // MYFUNCTIONS_H
