#include "mainwindow.h"

#include <QtDebug>
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QString dir = a.applicationDirPath();
    QString icoPth =dir+ "/images/pactos.ico";
    a.setWindowIcon(QIcon(icoPth));
    MainWindow w;
    w.show();
    return a.exec();
}
