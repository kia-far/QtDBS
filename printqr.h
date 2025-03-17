#ifndef PRINTQR_H
#define PRINTQR_H

#include <QAbstractItemModel>

class PrintQR : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit PrintQR(QObject *parent = nullptr);
    static void printQRCode(QStringList QRData,QString device);
    static bool checkConnection();


private:
};

#endif // PRINTQR_H
