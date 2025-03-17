#include "deleteitem.h"
#include "ui_deleteitem.h"
#include "itemhandler.h"
#include <QSqlQuery>
#include <QMessageBox>
#include "myfunctions.h"
#include "itemhandler.h"

DeleteItem::DeleteItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DeleteItem),
    db(DatabaseConnection::getInstance())
{
    ui->setupUi(this);
}

DeleteItem::~DeleteItem()
{
    delete ui;
}


void DeleteItem::setup(QString device){
    ui->label->setText("حذف قطعه "+ device);
    this->device = device;
    ui->listWidget->clear();
    ui->listWidget->addItems(ItemHandler::loadItems(device));
    this->show();
    this->activateWindow();
}

void DeleteItem::on_pushButton_clicked()
{
    QString msg = "";
    if(!checkItem(device,item).isEmpty()){
        for(unsigned int sn:checkItem(device,item)){

            msg.append( MyFunctions::intToStr(sn) + " ");

        }

        QMessageBox msgbox;
        msgbox.setIcon(QMessageBox::Warning);
        msgbox.setText("این قطعه توسط" +msg+" در حال استفاده میباشد");
        msgbox.setStandardButtons(QMessageBox::Ok);
        msgbox.exec();
        qDebug() << "not deleting ";
        qDebug() << "successful";}
    else{
        ItemHandler::deleteItem(device,item);
        ItemHandler::loadItems(item);
        emit refreshDevices(device);
        emit refreshTable();
        this->close();
    }
}
QVector<unsigned int> DeleteItem::checkItem(QString deviceName, QString itemName) {
    QVector<unsigned int> serialNumbers;
    QSqlQuery query(db.getConnection());

    QString res = QString("SELECT SerialNumber FROM " + deviceName + " WHERE " + itemName + " NOT LIKE 'هیچ کدام'");
    query.prepare(res);

    if (query.exec()) {
        while (query.next()) {
            bool ok;
            int serial = query.value(0).toInt(&ok);
            if (ok) {
                serialNumbers.append(serial); // Add only valid integers
            }
        }
    }else {
        qDebug() << "Query failed: " << query.lastError().text();
    }

    return serialNumbers;
}

void DeleteItem::on_listWidget_itemClicked(QListWidgetItem *item)
{
    this->item = item->text();
}

bool DeleteItem::deleteDone(QString device, QString item){
    ItemHandler::deleteItem(device , item);
    return true;
}
