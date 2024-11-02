#include "jsonhandler.h"
#include "itemhandler.h"
#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>

JsonHandler::JsonHandler(QObject *parent)
    : QAbstractItemModel(parent)
{

}
QString jsonPath;
QString fileName = "";
QString infoFileName = "";
bool errShown=false;

QJsonObject JsonHandler::loadJson() {
    QString adr = qApp->applicationDirPath();
    QString jsonPathFile = adr+"/JSONPath";
    QFile file(jsonPathFile);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        jsonPath = in.readLine();  // Read the database path from the file
        file.close();

        if (!jsonPath.isEmpty()) {
            // Open the json using the path from the file
        } else {
            if(!errShown){
                QMessageBox msgBox;
                msgBox.setIcon(QMessageBox::Critical);
                msgBox.setWindowTitle("Error");
                msgBox.setText("آدرس جیسون خالی است"
                               "در حال باز کردن جسیون محلی");
                msgBox.setStandardButtons(QMessageBox::Ok);
                msgBox.exec();
                errShown = true;
            }
            jsonPath=adr+"/JSON";
            qDebug() << "Json path file is empty!";
        }
    } else {
        qDebug() << "Failed to open database path file:" << file.errorString();
    }
    // QString addr = qApp->applicationDirPath();
    fileName = jsonPath+"/items.json";
    infoFileName = jsonPath + "/info.json";
    // qDebug()<<fileName << infoFileName;
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
    if(jsonPath.isEmpty()){
        loadJson();
    }
    // QString addr = qApp->applicationDirPath();
    fileName = jsonPath+"/items.json";
    infoFileName = jsonPath + "/info.json";
    QFile jsonFile(fileName);
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(document.toJson());
}

QJsonObject JsonHandler::loadInfoJson() {
    if(jsonPath.isEmpty()){
        loadJson();
    }
    // QString addr = qApp->applicationDirPath();
    fileName = jsonPath+"/items.json";
    infoFileName = jsonPath + "/info.json";
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
    if(jsonPath.isEmpty()){
        loadJson();
    }
    // QString addr = qApp->applicationDirPath();
    fileName = jsonPath+"/items.json";
    infoFileName = jsonPath + "/info.json";
    QFile jsonFile(infoFileName);
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(document.toJson());
}
