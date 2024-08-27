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
//    for( int i=0;i<tempstr.length();i++){
//        qDebug() << "device" << i << " is :" << tempstr[i];
//    }
    loadedObj = objs;
    loadedInfoObj = iObjs;
    return tempstr;
}
QStringList ItemHandler::loadItems(QString device){
//    qDebug() << "loadItems start";
    QJsonArray itemArr = loadedObj[device].toArray();
    QStringList tempstr;
    for (int i=0;i<itemArr.size();i++){
        tempstr.append(itemArr[i].toObject().begin().key());
    }
    qDebug() <<"item loaded: "<< tempstr;
//    qDebug() << "loadItems end";
    return tempstr;
}
QStringList ItemHandler::loadOptions(QString device, QString item){

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
    // Ensure device exists in loadedInfoObj
    if (!loadedInfoObj.contains(device)) {
        qDebug() << "Device not found!";
        return QStringList();
    }

    // Access the array associated with the device
    QJsonArray itemArr = loadedInfoObj[device].toArray();

    // Check if itemArr is not empty and contains at least one object
    if (itemArr.isEmpty()) {
        qDebug() << "No belongings found for device:" << device;
        return QStringList();
    }

    // Access the belongings array from the first object in itemArr
    QJsonArray belongingsArr = itemArr[0].toObject().value("belongings").toArray();

    QStringList tempstr;

    // Iterate through belongingsArr and populate tempstr
    for (const QJsonValue &value : belongingsArr) {
        tempstr.append(value.toString());
    }

    qDebug() << "Belongings loaded: " << tempstr;
    return tempstr;
}


void ItemHandler::addDevices(QString deviceName,QString deviceAbr) {
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
        qDebug() << "Table created successfully:" << deviceName;
    }
}
void ItemHandler::addBelonging(QString device, QString itemName) {
    // Check if the device exists in loadedInfoObj
    if (!loadedInfoObj.contains(device)) {
        // If not, create a new entry for this device
        QJsonArray newItemArr;
        QJsonObject newDeviceObj;
        newDeviceObj["belongings"] = newItemArr; // Initialize with an empty belongings array
        loadedInfoObj[device] = QJsonArray{ newDeviceObj }; // Set the device with the new object
    }

    // Access the belongings array for the device
    QJsonArray itemArr = loadedInfoObj[device].toArray();
    QJsonArray belongingsArr = itemArr[0].toObject().find("belongings").value().toArray();

    // Append the new item to the belongings array
    belongingsArr.append(itemName);

    // Update the JSON object with the modified belongings array
    QJsonObject updatedDeviceObj = itemArr[0].toObject();
    updatedDeviceObj["belongings"] = belongingsArr;
    itemArr[0] = updatedDeviceObj; // Update the item array with the modified object
    loadedInfoObj[device] = itemArr; // Update loadedInfoObj with the modified item array

    // Save the updated JSON back to file
    QJsonDocument someDoc(loadedInfoObj);
    JsonHandler::saveInfoJson(someDoc);


    qDebug() << "Added item:" << itemName << "to device:" << device;
}


//void ItemHandler::addDevices(QString deviceName,QJsonArray itemList) {
//    QJsonObject deviceObj = loadedObj;
//    deviceObj.insert(deviceName,itemList);
//    QJsonDocument updatedDoc(deviceObj);
//    JsonHandler::saveJson(updatedDoc);
//}

void ItemHandler::addItems(QString deviceName, QString itemName){
    QJsonArray deviceArr =loadedObj[deviceName].toArray();
    QJsonObject newItem;
    QJsonArray emptyArr;
    newItem.insert(itemName,emptyArr);
    deviceArr.append(newItem);
    QJsonObject deviceObj = loadedObj;
    deviceObj[deviceName] = deviceArr;
    QJsonDocument updatedDoc(deviceObj);
    JsonHandler::saveJson(updatedDoc);
    DatabaseConnection& db = DatabaseConnection::getInstance();
    QSqlQuery query(db.getConnection());
    QString addColumnQuery = QString("ALTER TABLE %1 ADD COLUMN %2 TEXT").arg(deviceName, itemName);

    if (!query.exec(addColumnQuery)) {
        qDebug() << "Failed to add column:" << query.lastError().text();
    } else {
        qDebug() << "Column added successfully:" << itemName << "to table:" << deviceName;
    }
}
void ItemHandler::addOptions(QString deviceName , QString itemName , QString optionName){
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
        qDebug() << "Data inserted successfully into table:" << tableName;
    }
}

void ItemHandler::addNewInfoDevice(QString deviceName, QString deviceAbr) {
    // Check if the device already exists
    if (loadedInfoObj.contains(deviceName)) {
        qDebug() << "Device already exists:" << deviceName;
        return; // Exit if the device already exists
    }

    // Create a new JSON object for the new device
    QJsonObject newDeviceObj;
    QJsonArray emptyBelongings; // Create an empty belongings array
    newDeviceObj["belongings"] = emptyBelongings; // Set belongings to empty

    // Create a QJsonArray to hold the new device object and its abbreviation
    QJsonArray deviceArray;
    deviceArray.append(newDeviceObj); // Append the belongings object
    deviceArray.append(deviceAbr);      // Append the device abbreviation

    // Add the new device array to loadedInfoObj
    loadedInfoObj[deviceName] = deviceArray;
    QJsonDocument somedoc(loadedInfoObj);

    // Save the updated JSON back to file
    JsonHandler::saveInfoJson(somedoc);

    qDebug() << "Added new device:" << deviceName << "with abbreviation:" << deviceAbr;
}

QStringList ItemHandler::readLetters() {
    QStringList res = {};
    QStringList allDevices = loadedInfoObj.keys(); // Assuming loadedInfoObj is a QJsonObject

    for (const QString &device : allDevices) {
        // Get the associated value for the device, which is an array
        QJsonValue deviceValue = loadedInfoObj.value(device);

        // Check if the value is an array
        if (deviceValue.isArray()) {
            QJsonArray deviceArray = deviceValue.toArray();

            // Check if the array has at least two elements
            if (deviceArray.size() > 1) {
                // The second element is the letter
                QString letter = deviceArray[1].toString();
                res.append(letter);
                qDebug() << "Device:" << device << "Letter:" << letter;
            }
        }
    }

    qDebug() << "Whole letters:" << res;
    return res;
}

