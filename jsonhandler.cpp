#include "jsonhandler.h"
#include "itemhandler.h"
#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>

JsonHandler::JsonHandler(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QString fileName = "";
QString infoFileName = "";

QJsonObject JsonHandler::loadJson() {
    QString addr = qApp->applicationDirPath();
    fileName = addr+"/JSON/items.json";
    infoFileName = addr + "/JSON/info.json";
    QJsonObject obj;
    QFile jsonFile(fileName);
    if (jsonFile.open(QFile::ReadOnly)) {
        QByteArray Bytes = jsonFile.readAll();
        jsonFile.close();
        QJsonParseError JsonError;
        QJsonDocument Document = QJsonDocument::fromJson(Bytes, &JsonError);

        if (JsonError.error != QJsonParseError::NoError) {
            qDebug() << "error in json data: " << JsonError.errorString();
        } else {
            if (Document.isObject()) {
                obj = Document.object();
            }
//            qDebug() << "hope this is shown in console :" << obj.contains("");

            // Clean up any empty key if found
            if (obj.contains("")) {
//                qDebug() << "Removing empty key from loaded JSON";
                obj.remove("");  // Remove the empty key
            }
        }
    }
    return obj;
}

void JsonHandler::saveJson(QJsonDocument document) {
    QString addr = qApp->applicationDirPath();
    fileName = addr+"/JSON/items.json";
    infoFileName = addr + "/JSON/info.json";
    QFile jsonFile(fileName);
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(document.toJson());
}

QJsonObject JsonHandler::loadInfoJson() {
    QString addr = qApp->applicationDirPath();
    fileName = addr+"/JSON/items.json";
    infoFileName = addr + "/JSON/info.json";
    QJsonObject obj;
    QFile jsonFile(infoFileName);
    if(jsonFile.open(QFile::ReadOnly)){
        QByteArray Bytes = jsonFile.readAll();
        jsonFile.close();
        QJsonParseError JsonError;
        QJsonDocument Document = QJsonDocument::fromJson(Bytes , &JsonError);
        if(JsonError.error != QJsonParseError::NoError){
            qDebug() << "error in json data : " << JsonError.errorString();
        }
        else{
//            /*qDebug() << "no error in json data. "*/;
        }
        if(Document.isObject()){
           obj = Document.object();
//        qDebug() << "obj = " << obj ;
//        qDebug() << "obj keys = " << obj.keys() ;
//        qDebug() << "obj length = " << obj.length() ;
//        qDebug() << "obj count = " << obj.count() ;
        }
    }
    return obj;
}
void JsonHandler::saveInfoJson(QJsonDocument document) {
    QString addr = qApp->applicationDirPath();
    fileName = addr+"/JSON/items.json";
    infoFileName = addr + "/JSON/info.json";
    QFile jsonFile(infoFileName);
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(document.toJson());
}
