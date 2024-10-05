#include "logger.h"
#include <QDateTime>
#include <QApplication>

logger::logger(QObject *parent)
    : QAbstractItemModel(parent)
     // You can specify the log file path here
{
}

void logger::log(QString text) {
    QFile file(qApp->applicationDirPath()+"/log.txt");

    // Open the file in append mode and text mode
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        // qDebug
        QTextStream out(&file);

        // Optionally, prepend the log entry with the current timestamp
        QString timeStamp = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        out << timeStamp << " - " << text << "\n";

        file.close();
    } else {
        // Handle the case where the file couldn't be opened
        qWarning("Unable to open log file for writing.");
    }
}
