#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QAbstractItemModel>
#include <QString>
#include <QFile>
#include <QTextStream>

class logger : public QAbstractItemModel {
    Q_OBJECT
public:
    explicit logger(QObject *parent = nullptr);
    static void log(QString text); // Logger method that writes the text to a text file
    // static QString logFilePath;

private:
};

#endif // LOGGER_H
