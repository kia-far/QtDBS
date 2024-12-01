#ifndef PRINTQR_H
#define PRINTQR_H

#include <QAbstractItemModel>

class PrintQR : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit PrintQR(QObject *parent = nullptr);
    static void printQRCode(QStringList QRData,QString device);

private:
};

#endif // PRINTQR_H
