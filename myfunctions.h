#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

#include <QAbstractItemModel>
#include <QSqlDatabase>

class MyFunctions : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit MyFunctions(QObject *parent = nullptr);
    static QString intToStr(unsigned int number);
    static QString reverseSN(const QString &input);
    static QString newReverseSN(const QString &input);
    static int binaryToDecimal(const QString& binary);
    static QString decimalToBinary(int decimal);
    static QString smallSN(QString a);
    static bool checkSN(QString sn);
    static QString querySolver();
    static int snLetter(QString letter);
    static QString searchHandler(QString column,QString tableName, QString searchParam ,QString searchText);
    // static bool deviceFromSN(QString SN,QString device);
    static bool deviceFromLetter(QString SN, QString device);
    static void setLetters();
    static QStringList getLetters();
    static bool enterAdminMode();
    static bool setAdminMode(bool isActive);
    static bool checkData(QString data,QString column, QString Table);
//    static void initializeData();
signals:
    void dataReady();
private:
    static int poslet;
    static QStringList letters;

};

#endif // MYFUNCTIONS_H
