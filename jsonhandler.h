#ifndef JSONHANDLER_H
#define JSONHANDLER_H

#include <QAbstractItemModel>

class JsonHandler : public QAbstractItemModel
{
    Q_OBJECT

public:
    QString addr;
    explicit JsonHandler(QObject *parent = nullptr);
    static QJsonObject loadJson();
    static void saveJson(QJsonDocument document);
    static QJsonObject loadInfoJson();
    static void saveInfoJson(QJsonDocument document);
    QString getFile ();



private:

};

#endif // JSONHANDLER_H
