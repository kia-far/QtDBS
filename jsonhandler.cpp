#include "jsonhandler.h"
#include "itemhandler.h"
#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>

JsonHandler::JsonHandler(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QString fileName = "C:/Users/kiafa/Documents/build-QtDBS-Desktop_Qt_5_12_12_MinGW_64_bit-Debug/history/items.json";
QString infoFileName = "C:/Users/kiafa/Documents/build-QtDBS-Desktop_Qt_5_12_12_MinGW_64_bit-Debug/history/info.json";

QJsonObject JsonHandler::loadJson() {

    QJsonObject obj;
    QFile jsonFile(fileName);
    if(jsonFile.open(QFile::ReadOnly)){
        QByteArray Bytes = jsonFile.readAll();
        jsonFile.close();
        QJsonParseError JsonError;
        QJsonDocument Document = QJsonDocument::fromJson(Bytes , &JsonError);
        if(JsonError.error != QJsonParseError::NoError){
            qDebug() << "error in json data : " << JsonError.errorString();
        }
        else{
//            qDebug() << "no error in json data. ";
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
void JsonHandler::saveJson(QJsonDocument document) {
    QFile jsonFile(fileName);
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(document.toJson());
}

QJsonObject JsonHandler::loadInfoJson() {

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
    QFile jsonFile(infoFileName);
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(document.toJson());
}
