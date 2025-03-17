#include "printqr.h"
#include "DllHandler.h"
#include "loadqrtext.h"
#include <QDebug>
#include <QApplication>
#include "itemhandler.h"
#include <logger.h>
#include <QMessageBox>

PrintQR::PrintQR(QObject *parent)
    : QAbstractItemModel(parent)
{}
void PrintQR::printQRCode(QStringList QRData,QString device) {

    if (!DllHandler::loadDll("WINPSK")) {  // No need to include .dll
        qDebug() << "hi";
        // return -1;
    }
    QString fullDeviceName = ItemHandler::getDeviceFullName(device);
    QString adr = qApp->applicationDirPath();
    QString QRPathFile = adr+"/QRPath";
    QString text = LoadQRText::loadText(QRPathFile);
    QString newText = text.toUtf8();
    newText.replace("serialnumber", QRData.at(0).toUtf8());
    newText.replace("devicename", fullDeviceName.toUtf8());
    newText.replace("customername", QRData.at(1).toUtf8());
    newText.replace("xxxx/xx/xx", QRData.at(4).toUtf8());
    newText.replace("yyyy/yy/yy", QRData.at(5).toUtf8());
    newText.replace("\n","\r");
    // qDebug() << newText;
    // qDebug() << newText.toUtf8();
    // QString logext = LoadQRText::loadText(LoadQRText::loadText(QRPathFile)+"\\QRText");
    logger::log(newText+ " is being printed to the QR code!");
    logger::log(QString::number( DllHandler::closePort())+" closeport return value");
    int open = DllHandler::openPort(1);
    if( open <0){
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("ERROR");
        msgBox.setText("پرینتر وصل نیست!");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }
    logger::log(QString::number(open)+" openport return value");
    logger::log(QString::number(DllHandler::clearbuffer())+" clearbuffer return value");
    logger::log(QString::number(DllHandler::setDirection('B'))+" setDirection return value");
    logger::log(QString::number( DllHandler::setPrintSpeed(1))+" setprintspeed return value");
    logger::log(QString::number(DllHandler::setLabelWidth(420))+" setlabelwidth return value");
    logger::log(QString::number( DllHandler::setFont(230,110,0,4,1,1,'N',QRData.at(0).toUtf8().constData()))+"print text return value");
    logger::log(QString::number(DllHandler::drawQRCode(75, 25, newText))+" print qr code return value");
    logger::log(QString::number( DllHandler::drawBarCode(230,40, QRData.at(0)))+" print parcode return value");
    logger::log(QString::number(DllHandler::printLabel(1, 1))+" print return value");
    logger::log(QString::number(DllHandler::closePort())+" closeport 2 return value");
    DllHandler::unloadDll();
}

bool PrintQR::checkConnection(){
    if (!DllHandler::loadDll("WINPSK")) {  // No need to include .dll
        qDebug() << "hi";
        // return -1;
    }
    int open = DllHandler::openPort(1);
    if(open<1){return false;}
    else {return true;}
}
