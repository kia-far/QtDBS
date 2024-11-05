#ifndef ITEMHANDLER_H
#define ITEMHANDLER_H

#include <QAbstractItemModel>
#include "DatabaseConnection.h"

class ItemHandler : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit ItemHandler(QObject *parent = nullptr);
    static void recieveData();
    static QStringList loadDevices();
    static QStringList loadItems(QString device);
    static QStringList loadOptions(QString device , QString item);
    static QStringList loadbelongings(QString device);
    static void addDevices(QString deviceName,QString DeviceAbr);
    static void addNewInfoDevice(QString deviceName,QString deviceAbr);
    static void addItems(QString device, QString itemName);
    static void editItem(QString device, QString oldItem, QString newItem);
    static void addOptions(QString deviceName , QString itemName, QString optionName);
    static void removeOptions(QString deviceName,QString itemName,QString optionName);
    static void addBelonging(QString deviceName, QString itemName);
    static void insertDataIntoTable(const QString& tableName, const QStringList& columnNames, const QVariantList& dataValues);
    static void updateTable(const QString& tableName, const QStringList& columnNames, const QVariantList& dataValues);
    static QStringList readLetters();
    static QStringList nameLetter();
    static void addAbr(QString device,QChar newAbr);

private:
    DatabaseConnection &db;

};

#endif // ITEMHANDLER_H
