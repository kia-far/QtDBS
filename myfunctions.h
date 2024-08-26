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


private:
   static int poslet;
};

#endif // MYFUNCTIONS_H
