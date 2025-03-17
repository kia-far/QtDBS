#include "itemhandler.h"
#include "jsonhandler.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>
#include <QFile>
#include <QSqlQuery>
#include "logger.h"

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
    // qDebug() << "i ran";
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
    loadDevices();
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
                    QJsonObject belongingObj = value.toObject();
                    if (belongingObj.contains("item") /*&& belongingObj.value("visible").toInt() == 1*/) {
                        tempstr.append(belongingObj.value("item").toString());
                    }
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
        return QStringList();
    }
    return tempstr;
}

QStringList ItemHandler::loadVisibleBelongings(QString device){
    {
        loadDevices();
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
                        QJsonObject belongingObj = value.toObject();
                        if (belongingObj.contains("item") && belongingObj.value("visible").toInt() == 1) {
                            tempstr.append(belongingObj.value("item").toString());
                        }
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
            return QStringList();
        }
        return tempstr;
}
}

void ItemHandler::addDevices(QString deviceName,QString deviceAbr, QString deviceFullName) {

    loadDevices();
    addNewInfoDevice(deviceName,deviceAbr,deviceFullName);
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
    loadDevices();
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

            // Create a new belonging object with "item" and "visible"
            QJsonObject newBelonging;
            newBelonging["item"] = itemName;
            newBelonging["visible"] = 1;  // Set new item as visible by default

            belongingsArr.append(newBelonging);
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
}



//void ItemHandler::addDevices(QString deviceName,QJsonArray itemList) {
//    QJsonObject deviceObj = loadedObj;
//    deviceObj.insert(deviceName,itemList);
//    QJsonDocument updatedDoc(deviceObj);
//    JsonHandler::saveJson(updatedDoc);
//}

void ItemHandler::addItems(QString deviceName, QString itemName) {
    loadDevices();
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
    QString addColumnQuery = QString("ALTER TABLE %1 ADD COLUMN %2 TEXT NOT NULL DEFAULT 'هیچ کدام'").arg(deviceName, itemName);

    if (!query.exec(addColumnQuery)) {
        qDebug() << "Failed to add column:" << query.lastError().text();
    } else {
//        qDebug() << "Column added successfully:" << itemName << "to table:" << deviceName;
    }
    loadDevices();
}
void ItemHandler::editItem(QString device, QString oldItem, QString newItem) {
    loadDevices();

    if (!loadedObj.contains(device)) {
        qDebug() << "Error: Device not found in JSON while editing item.";
        return;
    }

    QJsonArray deviceArr = loadedObj[device].toArray();
    bool itemFound = false;
    QJsonArray itemContents;

    // Loop through items in the device array to find the old item
    for (int i = 0; i < deviceArr.size(); ++i) {
        QJsonObject itemObj = deviceArr[i].toObject();
        if (itemObj.contains(oldItem)) {
            // Store the existing contents of the old item
            itemContents = itemObj.value(oldItem).toArray();

            // Remove the old item
            deviceArr.removeAt(i);

            // Add the new item with the stored contents
            QJsonObject newItemObj;
            newItemObj.insert(newItem, itemContents);
            deviceArr.insert(i, newItemObj);

            itemFound = true;
            break;
        }
    }

    if (!itemFound) {
        qDebug() << "Warning: Item not found for editing.";
        return;
    }

    // Update the JSON object
    loadedObj[device] = deviceArr;
    QJsonDocument updatedDoc(loadedObj);
    JsonHandler::saveJson(updatedDoc);

    // Update the database table
    DatabaseConnection& db = DatabaseConnection::getInstance();
    QSqlQuery query(db.getConnection());

    // First, rename the column in the database
    QString renameColumnQuery = QString("ALTER TABLE %1 RENAME COLUMN %2 TO %3").arg(device, oldItem, newItem);
    if (!query.exec(renameColumnQuery)) {
        qDebug() << "Failed to rename column:" << query.lastError().text();
    } else {
        qDebug() << "Column renamed successfully from" << oldItem << "to" << newItem;
    }

    loadDevices();
}

void ItemHandler::deleteItem(QString device, QString itemToDelete) {
    loadDevices();
    if (!loadedObj.contains(device)) {
        qDebug() << "Error: Device not found in JSON while deleting item.";
        return;
    }
    QJsonArray deviceArr = loadedObj[device].toArray();
    bool itemFound = false;
    // Loop through items in the device array to find and remove the item
    for (int i = 0; i < deviceArr.size(); ++i) {
        QJsonObject itemObj = deviceArr[i].toObject();
        if (itemObj.contains(itemToDelete)) {
            deviceArr.removeAt(i); // Remove the item from JSON
            itemFound = true;
            break;
        }
    }
    if (!itemFound) {
        qDebug() << "Warning: Item not found for deletion.";
        return;
    }
    // Update the JSON object
    loadedObj[device] = deviceArr;
    QJsonDocument updatedDoc(loadedObj);
    JsonHandler::saveJson(updatedDoc);

    // Remove the column from the database table using the SQLite workaround
    DatabaseConnection& db = DatabaseConnection::getInstance();
    QSqlDatabase dbConn = db.getConnection();
    QSqlQuery query(dbConn);

    // Start a transaction
    if (!query.exec("BEGIN TRANSACTION")) {
        qDebug() << "Failed to start transaction:" << query.lastError().text();
        return;
    }

    try {
        // Get table info to create new table with same structure minus the deleted column
        QString pragmaQuery = QString("PRAGMA table_info(%1)").arg(device);
        if (!query.exec(pragmaQuery)) {
            throw QString("Failed to get table info: %1").arg(query.lastError().text());
        }

        // Build the CREATE TABLE statement parts
        QStringList columnDefinitions;
        QStringList columnNames;
        QString primaryKey;

        while (query.next()) {
            QString colName = query.value(1).toString();
            QString colType = query.value(2).toString();
            int notNull = query.value(3).toInt();
            QString defaultValue = query.value(4).toString();
            int isPK = query.value(5).toInt();

            // Skip the column we want to delete
            if (colName.compare(itemToDelete, Qt::CaseInsensitive) == 0) {
                continue;
            }

            // Build column definition
            QString colDef = colName + " " + colType;
            if (notNull) {
                colDef += " NOT NULL";
            }
            if (!defaultValue.isEmpty()) {
                colDef += " DEFAULT " + defaultValue;
            }
            if (isPK) {
                colDef += " PRIMARY KEY";
                primaryKey = colName;
            }

            columnDefinitions.append(colDef);
            columnNames.append(colName);
        }

        if (columnDefinitions.isEmpty()) {
            throw QString("No columns found or all columns would be dropped");
        }

        // Create new table with correct structure
        QString createNewTableSQL = QString("CREATE TABLE temp_%1 (%2)").arg(device).arg(columnDefinitions.join(", "));
        qDebug() << "Creating table with: " << createNewTableSQL;

        if (!query.exec(createNewTableSQL)) {
            throw QString("Failed to create new table: %1").arg(query.lastError().text());
        }

        // Copy data from old table to new table
        QString copyDataSQL = QString("INSERT INTO temp_%1 SELECT %2 FROM %1")
                                  .arg(device)
                                  .arg(columnNames.join(", "));
        qDebug() << "Copying data with: " << copyDataSQL;

        if (!query.exec(copyDataSQL)) {
            throw QString("Failed to copy data: %1").arg(query.lastError().text());
        }

        // Drop old table
        QString dropOldTableSQL = QString("DROP TABLE %1").arg(device);
        if (!query.exec(dropOldTableSQL)) {
            throw QString("Failed to drop old table: %1").arg(query.lastError().text());
        }

        // Rename new table
        QString renameTableSQL = QString("ALTER TABLE temp_%1 RENAME TO %1").arg(device);
        if (!query.exec(renameTableSQL)) {
            throw QString("Failed to rename table: %1").arg(query.lastError().text());
        }

        if (!query.exec("COMMIT")) {
            throw QString("Failed to commit transaction: %1").arg(query.lastError().text());
        }

        qDebug() << "Column deleted successfully:" << itemToDelete;
    }
    catch (const QString& errorMsg) {
        qDebug() << errorMsg;
        query.exec("ROLLBACK");
        qDebug() << "Transaction rolled back due to error";
    }

    loadDevices();
}


void ItemHandler::addOptions(QString deviceName , QString itemName , QString optionName){
    loadDevices();
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

//
void ItemHandler::removeOptions(QString deviceName, QString itemName, QString optionName) {
    if(optionName=="هیچ کدام"){

    }
    else{
    loadDevices();
    QJsonArray itemArr = loadedObj[deviceName].toArray();
    bool iscorrect = false;
    int i = 0;

    // Find the item in the JSON array
    while (!iscorrect && i < itemArr.size()) {
        if (itemArr[i].toObject().begin().key() == itemName) {
            QJsonArray optionArray = itemArr[i].toObject().begin().value().toArray();

            // Search for and remove the specified option
            for (int j = 0; j < optionArray.size(); ++j) {
                // qDebug() << optionArray[j];
                if (optionArray[j].toString() == optionName) {
                    // qDebug() << "option found";
                    optionArray.removeAt(j);
                    break;
                }
            }

            // Update the item with the modified array
            QJsonObject updatedItemObj = itemArr[i].toObject();
            updatedItemObj[itemName] = optionArray;
            itemArr[i] = updatedItemObj;
            loadedObj[deviceName] = itemArr;

            iscorrect = true;
        }
        i++;
    }

    // Save the updated JSON document
    QJsonDocument updatedDoc(loadedObj);
    JsonHandler::saveJson(updatedDoc);
    loadDevices();
    }}

//
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
        qDebug() << "Failed to insert data to :"<<tableName<<columnNames << query.lastError().text();
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
        logger::log("Failed to update data:" + query.lastError().text());
        qDebug() << "Failed to update data:" << query.lastError().text();
    } else {
        logger::log("Data updated successfully in table:" + tableName);
        // qDebug() << "Data updated successfully in table:" << tableName;
    }
}


void ItemHandler::addNewInfoDevice(QString deviceName, QString deviceAbr, QString deviceFullName) {
    loadDevices();
    QJsonArray devicesArray = loadedInfoObj["devices"].toArray();

    // Check if the device already exists
    for (const QJsonValue &device : devicesArray) {
        if (device.toObject().contains(deviceName)) {
            qDebug() << "Device already exists:" << deviceName;
            return;
        }
    }

    // Create a new device object compatible with the new format
    QJsonObject newDeviceObj;
    QJsonArray emptyBelongings;  // Initialize an empty belongings array
    newDeviceObj["belongings"] = emptyBelongings;
    newDeviceObj["fullName"] = deviceFullName;  // Add full name to the device object

    QJsonArray newDeviceEntry;
    newDeviceEntry.append(newDeviceObj);  // First element: belongings object with fullName
    newDeviceEntry.append(deviceAbr);     // Second element: device abbreviation

    QJsonObject deviceObject;
    deviceObject[deviceName] = newDeviceEntry;

    devicesArray.append(deviceObject);

    loadedInfoObj["devices"] = devicesArray;
    QJsonDocument somedoc(loadedInfoObj);

    JsonHandler::saveInfoJson(somedoc);
    loadDevices();
    logger::log("Added new device: " + deviceName + " with abbreviation: " + deviceAbr + " and full name: " + deviceFullName);
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
    loadDevices();
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
    QString addedAbr = "";
    addedAbr.append(newAbr);
    logger::log("Abbreviation added successfully! " + addedAbr);
    loadDevices();
    // qDebug() << "Abbreviation added successfully!";
}

void ItemHandler::changeBelVisibility(QString device, QString belonging) {
    // Load the JSON data if not already loaded
    loadDevices();
    if (!loadedInfoObj.contains("devices")) {
        qDebug() << "No devices found.";
        return;
    }

    QJsonArray devicesArray = loadedInfoObj["devices"].toArray();
    bool deviceFound = false;
    bool belongingFound = false;

    // Find the device in the array
    for (int i = 0; i < devicesArray.size(); ++i) {
        QJsonObject deviceObj = devicesArray[i].toObject();
        if (deviceObj.contains(device)) {
            QJsonArray deviceEntry = deviceObj[device].toArray();
            QJsonObject belongingsObj = deviceEntry[0].toObject();
            QJsonArray belongingsArr = belongingsObj.value("belongings").toArray();

            // Find the specified belonging in the belongings array
            for (int j = 0; j < belongingsArr.size(); ++j) {
                QJsonObject belongingObj = belongingsArr[j].toObject();
                if (belongingObj["item"].toString() == belonging) {
                    int currentVisibility = belongingObj["visible"].toInt();
                    belongingObj["visible"] = currentVisibility == 1 ? 0 : 1;  // Toggle visibility
                    belongingsArr[j] = belongingObj;  // Update the belonging in the array
                    belongingFound = true;
                    break;
                }
            }

            // Update belongings array if the belonging was found
            if (belongingFound) {
                belongingsObj["belongings"] = belongingsArr;
                deviceEntry[0] = belongingsObj;
                deviceObj[device] = deviceEntry;
                devicesArray[i] = deviceObj;
                deviceFound = true;
                break;
            }
        }
    }

    if (!deviceFound) {
        qDebug() << "Device not found:" << device;
    } else if (!belongingFound) {
        qDebug() << "Belonging not found:" << belonging << "for device:" << device;
    } else {
        // Save updated JSON if device and belonging were found
        loadedInfoObj["devices"] = devicesArray;
        QJsonDocument updatedDoc(loadedInfoObj);
        JsonHandler::saveInfoJson(updatedDoc);  // Save the JSON document
        qDebug() << "Visibility toggled for belonging:" << belonging << "in device:" << device;
    }
}

QString ItemHandler::getDeviceFullName(QString deviceName) {
    loadDevices();

    if (!loadedInfoObj.contains("devices")) {
        qDebug() << "No devices found.";
        return QString();
    }

    QJsonArray devicesArray = loadedInfoObj["devices"].toArray();

    // Search for the specified device
    for (const QJsonValue &deviceValue : devicesArray) {
        QJsonObject deviceObj = deviceValue.toObject();
        if (deviceObj.contains(deviceName)) {
            QJsonArray deviceEntry = deviceObj[deviceName].toArray();
            if (!deviceEntry.isEmpty()) {
                QJsonObject belongingsObj = deviceEntry[0].toObject();
                if (belongingsObj.contains("fullName")) {
                    return belongingsObj["fullName"].toString(); // Return the full name
                } else {
                    qDebug() << "Full name not found for device:" << deviceName;
                    return QString();
                }
            } else {
                qDebug() << "Device entry is empty for device:" << deviceName;
                return QString();
            }
        }
    }

    qDebug() << "Device not found:" << deviceName;
    return QString();
}
