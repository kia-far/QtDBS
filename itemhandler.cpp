#include "itemhandler.h"
#include "jsonhandler.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>
#include <QFile>
#include <QSqlQuery>

ItemHandler::ItemHandler(QObject *parent)
    : QAbstractItemModel(parent),
      db(DatabaseConnection::getInstance())
{
    loadDevices();
}
QJsonObject loadedObj;
QJsonObject loadedInfoObj;

void recieveData(){

    JsonHandler::loadJson();

}
QStringList ItemHandler::loadDevices(){


    QJsonObject objs = JsonHandler::loadJson();
    QJsonObject iObjs = JsonHandler::loadInfoJson();
    QStringList tempstr = objs.keys();

    loadedObj = objs;
    qDebug() << "i ran";
    loadedInfoObj = iObjs;
    return tempstr;

}
QStringList ItemHandler::loadItems(QString device){

    QJsonArray itemArr = loadedObj[device].toArray();
    QStringList tempstr;
    for (int i=0;i<itemArr.size();i++){
        tempstr.append(itemArr[i].toObject().begin().key());
    }

    return tempstr;
}
QStringList ItemHandler::loadOptions(QString device, QString item){
    // loadDevices();
    QJsonArray itemArr = loadedObj[device].toArray();
    QStringList tempstr;
    QJsonArray newArr;
    bool iscorrect =false;
    int i =0;
    while(iscorrect == false){
        if (itemArr[i].toObject().begin().key()==item){
            newArr = itemArr[i].toObject().begin().value().toArray();
            iscorrect = true;
        }
        i+=1;
    }
    for (int j=0;j<newArr.size();j++){
        tempstr.append(newArr[j].toString());
    }
    return tempstr;
}

QStringList ItemHandler::loadbelongings(QString device) {
    // loadDevices();
    if (!loadedInfoObj.contains("devices")) {
        qDebug() << "No devices found.";
        return QStringList();
    }
    QJsonArray devicesArray = loadedInfoObj["devices"].toArray();
    bool deviceFound = false;
    QStringList tempstr;
    for (const QJsonValue &deviceValue : devicesArray) {
        QJsonObject deviceObj = deviceValue.toObject();
        if (deviceObj.contains(device)) {
            QJsonArray deviceEntry = deviceObj[device].toArray();
            if (!deviceEntry.isEmpty()) {
                QJsonArray belongingsArr = deviceEntry[0].toObject().value("belongings").toArray();
                for (const QJsonValue &value : belongingsArr) {
                    tempstr.append(value.toString());
                }
                deviceFound = true;
                break;
            } else {
                qDebug() << "No belongings found for device:" << device;
                return QStringList();
            }
        }
    }
    if (!deviceFound) {
        qDebug() << "Device not found:" << device;
        return QStringList();
    }
//    qDebug() << "Belongings loaded: " << tempstr;
    return tempstr;
}



void ItemHandler::addDevices(QString deviceName,QString deviceAbr) {
    // loadDevices();
    addNewInfoDevice(deviceName,deviceAbr);
    QJsonObject deviceObj = loadedObj;
    QJsonArray emptyArr;
    deviceObj.insert(deviceName,emptyArr);
    QJsonDocument updatedDoc(deviceObj);
    JsonHandler::saveJson(updatedDoc);
    DatabaseConnection& db = DatabaseConnection::getInstance();
    QSqlQuery query(db.getConnection());
    QString createTableQuery = QString("CREATE TABLE IF NOT EXISTS %1 (SerialNumber INTEGER PRIMARY KEY,CustomerName TEXT ,description TEXT, belongings TEXT)").arg(deviceName);

    if (!query.exec(createTableQuery)) {
        qDebug() << "Failed to create table:" << query.lastError().text();
    } else {
//        qDebug() << "Table created successfully:" << deviceName;
    }
    loadDevices();
}
void ItemHandler::addBelonging(QString device, QString itemName) {
    // loadDevices();
    if (!loadedInfoObj.contains("devices")) {
        qDebug() << "No devices found.";
        return;

    }

    QJsonArray devicesArray = loadedInfoObj["devices"].toArray();
    bool deviceFound = false;

    for (int i = 0; i < devicesArray.size(); ++i) {
        QJsonObject deviceObj = devicesArray[i].toObject();
        if (deviceObj.contains(device)) {
            QJsonArray deviceEntry = deviceObj[device].toArray();
            QJsonArray belongingsArr = deviceEntry[0].toObject().value("belongings").toArray();
            belongingsArr.append(itemName);
            QJsonObject updatedDeviceObj = deviceEntry[0].toObject();
            updatedDeviceObj["belongings"] = belongingsArr;
            deviceEntry[0] = updatedDeviceObj;

            deviceObj[device] = deviceEntry;
            devicesArray[i] = deviceObj;

            deviceFound = true;
            break;
        }
    }
    if (!deviceFound) {
        qDebug() << "Device not found:" << device;
        return;
    }
    loadedInfoObj["devices"] = devicesArray;
    QJsonDocument someDoc(loadedInfoObj);
    JsonHandler::saveInfoJson(someDoc);
    loadDevices();

//    qDebug() << "Added item:" << itemName << "to device:" << device;
}



//void ItemHandler::addDevices(QString deviceName,QJsonArray itemList) {
//    QJsonObject deviceObj = loadedObj;
//    deviceObj.insert(deviceName,itemList);
//    QJsonDocument updatedDoc(deviceObj);
//    JsonHandler::saveJson(updatedDoc);
//}

void ItemHandler::addItems(QString deviceName, QString itemName) {
    // loadDevices();
    // qDebug() << "Device Name:" << deviceName;
    if (deviceName.isEmpty()) {
        qDebug() << "Error: deviceName is empty. Aborting.";
        return; // Exit early if deviceName is invalid
    }
    if (loadedObj.contains("")) {
        qDebug() << "Warning: loadedObj contains an empty key!";
    }
    QJsonArray deviceArr =loadedObj[deviceName].toArray();
    QJsonObject newItem;
    QJsonArray emptyArr;
    newItem.insert(itemName,emptyArr);
    deviceArr.append(newItem);
    QJsonObject deviceObj = loadedObj;
    deviceObj[deviceName] = deviceArr;
    QJsonDocument updatedDoc(deviceObj);
    loadedObj = deviceObj;
    JsonHandler::saveJson(updatedDoc);
    DatabaseConnection& db = DatabaseConnection::getInstance();
    QSqlQuery query(db.getConnection());
    QString addColumnQuery = QString("ALTER TABLE %1 ADD COLUMN %2 TEXT").arg(deviceName, itemName);

    if (!query.exec(addColumnQuery)) {
        qDebug() << "Failed to add column:" << query.lastError().text();
    } else {
//        qDebug() << "Column added successfully:" << itemName << "to table:" << deviceName;
    }
    loadDevices();
}
void ItemHandler::addOptions(QString deviceName , QString itemName , QString optionName){
    // loadDevices();
    QJsonArray itemArr = loadedObj[deviceName].toArray();
    QStringList tempstr;
    QJsonArray newArr;
    bool iscorrect =false;
    int i =0;
    while(iscorrect == false){
        if (itemArr[i].toObject().begin().key()==itemName){
            newArr = itemArr[i].toObject().begin().value().toArray();
            iscorrect = true;
        }
        i+=1;
    }
    newArr.append(optionName);
    QJsonObject updatedItemObj = itemArr[i - 1].toObject(); // Use i-1 because i was incremented after the last match
    updatedItemObj[itemName] = newArr;
    itemArr[i - 1] = updatedItemObj;
    loadedObj[deviceName] = itemArr;
    QJsonDocument updatedDoc(loadedObj);
    JsonHandler::saveJson(updatedDoc);
    loadDevices();;
}

void ItemHandler::insertDataIntoTable(const QString& tableName, const QStringList& columnNames, const QVariantList& dataValues) {
    DatabaseConnection& db = DatabaseConnection::getInstance();



    // Construct the SQL query for inserting data
    QStringList placeholders;
    for (int i = 0; i < dataValues.size(); ++i) {
        placeholders << "?"; // Use placeholders for prepared statement
    }

    QString insertQuery = QString("INSERT INTO %1 (%2) VALUES (%3)")
                          .arg(tableName)
                          .arg(columnNames.join(", "))
                          .arg(placeholders.join(", "));
    QSqlQuery query(db.getConnection());


    query.prepare(insertQuery);
    for (int i = 0; i < dataValues.size(); ++i) {
        query.bindValue(i, dataValues[i]);
    }
    if (!query.exec()) {
        qDebug() << "Failed to insert data:" << query.lastError().text();
    } else {
//        qDebug() << "Data inserted successfully into table:" << tableName;
    }
}
void ItemHandler::updateTable(const QString &tableName, const QStringList &columnNames, const QVariantList &dataValues) {
    DatabaseConnection& db = DatabaseConnection::getInstance();

    // Check if there are enough columns and data values
    if (columnNames.size() != dataValues.size() || dataValues.isEmpty()) {
        qDebug() << "Column names and data values size mismatch or empty data values.";
        return;
    }

    // Extract the serial number (the first column) and prepare the update statement
    QVariant serialNumber = dataValues[0]; // Assuming the first value is the serial number
    QStringList setClauses;

    // Prepare the SET clauses for the UPDATE statement
    for (int i = 1; i < columnNames.size(); ++i) { // Start from 1 to skip the serial number
        setClauses << QString("%1 = ?").arg(columnNames[i]); // Use placeholders for prepared statement
    }

    // Construct the SQL UPDATE query
    QString updateQuery = QString("UPDATE %1 SET %2 WHERE %3 = ?")
                          .arg(tableName)
                          .arg(setClauses.join(", "))
                          .arg(columnNames[0]); // Use the first column as the WHERE clause

    QSqlQuery query(db.getConnection());
    query.prepare(updateQuery);

    // Bind values for the SET clauses
    for (int i = 1; i < dataValues.size(); ++i) {
        query.bindValue(i - 1, dataValues[i]); // Bind starting from index 0 for the SET values
    }

    // Bind the serial number for the WHERE clause
    query.bindValue(dataValues.size() - 1, serialNumber); // Last bind value is the serial number

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to update data:" << query.lastError().text();
    } else {
        // qDebug() << "Data updated successfully in table:" << tableName;
    }
}


void ItemHandler::addNewInfoDevice(QString deviceName, QString deviceAbr) {
    // loadDevices();
    QJsonArray devicesArray = loadedInfoObj["devices"].toArray();
    for (const QJsonValue &device : devicesArray) {
        if (device.toObject().contains(deviceName)) {
            qDebug() << "Device already exists:" << deviceName;
            return;
        }
    }
    QJsonObject newDeviceObj;
    QJsonArray emptyBelongings;
    newDeviceObj["belongings"] = emptyBelongings;

    QJsonArray newDeviceEntry;
    newDeviceEntry.append(newDeviceObj);
    newDeviceEntry.append(deviceAbr);

    QJsonObject deviceObject;
    deviceObject[deviceName] = newDeviceEntry;

    devicesArray.append(deviceObject);

    loadedInfoObj["devices"] = devicesArray;
    QJsonDocument somedoc(loadedInfoObj);

    JsonHandler::saveInfoJson(somedoc);
    loadDevices();;

//    qDebug() << "Added new device:" << deviceName << "with abbreviation:" << deviceAbr;
}


QStringList ItemHandler::readLetters() {
    // loadDevices();
    QStringList res = {};
    QJsonArray deviceArr = loadedInfoObj["devices"].toArray(); // Assuming loadedInfoObj is a QJsonObject
    QStringList objNames;
    QStringList allDevices ={};
    for (int i=0;i<deviceArr.size();i++){
        objNames = deviceArr[i].toObject().keys();
        for(int j=1;j<deviceArr[i].toObject().value(objNames[0]).toArray().size();j++){
            res.append(deviceArr[i].toObject().value(objNames[0]).toArray()[j].toString());

        }
    }
       // qDebug() << "Whole letters:" << res;
    return res;
}
QStringList ItemHandler::nameLetter() {
    // loadDevices();
    QStringList res;
    QJsonArray deviceArr = loadedInfoObj["devices"].toArray();

    for (const QJsonValue& deviceObj : deviceArr) {
        QString deviceName = deviceObj.toObject().keys().first();
        res.append(deviceName);

        for(int i=1;i<deviceObj.toObject()[deviceName].toArray().size();i++){
        QString firstLetter = deviceObj.toObject()[deviceName].toArray()[i].toString();

        res.append(firstLetter);
        }
    }
    // qDebug () << res;
    return res;
}

void ItemHandler::addAbr(QString deviceName, QChar newAbr) {
    // loadDevices();
    newAbr = newAbr.toUpper();

    // Load the device array
    QJsonArray deviceArr = loadedInfoObj["devices"].toArray();
    bool deviceFound = false;
    int deviceIndex = -1;
    QJsonArray itemArr;

    // Find the device in the array
    for (int i = 0; i < deviceArr.size(); ++i) {
        QJsonObject deviceObj = deviceArr[i].toObject();
        if (deviceObj.contains(deviceName)) {
            itemArr = deviceObj[deviceName].toArray();
            deviceFound = true;
            deviceIndex = i;
            break;
        }
    }

    if (!deviceFound) {
        qDebug() << "Device not found!";
        return;
    }

    // Check if the device has belongings and abbreviations
    if (itemArr.size() < 2) {
        qDebug() << "Invalid device structure!";
        return;
    }

    // Get the existing abbreviations (starting from the second item in the array)
    QStringList abrList;
    for (int i = 1; i < itemArr.size(); ++i) {
        abrList.append(itemArr[i].toString());
    }

    // If the new abbreviation is not already in the list, append it
    if (!abrList.contains(newAbr)) {
        abrList.append(newAbr);
    }

    // Update the array with the new abbreviations (keeping the belongings as the first item)
    QJsonArray newArr;
    newArr.append(itemArr[0]);  // Keep belongings object as the first element
    for (const QString& abr : abrList) {
        newArr.append(abr);
    }

    // Update the device object with the new array
    QJsonObject updatedDeviceObj = deviceArr[deviceIndex].toObject();
    updatedDeviceObj[deviceName] = newArr;
    deviceArr[deviceIndex] = updatedDeviceObj;

    // Save the updated array back to the loaded JSON object
    loadedInfoObj["devices"] = deviceArr;

    // Save the changes to the JSON file
    QJsonDocument updatedDoc(loadedInfoObj);
    JsonHandler::saveInfoJson(updatedDoc);

    loadDevices();
    // qDebug() << "Abbreviation added successfully!";
}


