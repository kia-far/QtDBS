#include "edittable.h"
#include "ui_edittable.h"
#include "productedit.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>



EditTable::EditTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditTable),
    model(new ProductEdit(this)),
    db(DatabaseConnection::getInstance())
{
    ui->setupUi(this);

    // Setup the model for the table view
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    dbe = QSqlDatabase::addDatabase("QSQLITE");
//    dbe.setDatabaseName("C:\\Users\\kiafa\\Desktop\\Job\\DB\\sqlitestudio_x64-3.4.4\\SQLiteStudio\\InfoDB");
//    dbe.open();
}
int currentIndex;
int currentSerialNum;
QSqlTableModel *customerModel;
QSqlTableModel *serviceModel;

EditTable::~EditTable()
{
    delete ui;
    delete customerModel;
    delete serviceModel;
}



void EditTable::receiveTableIndex(unsigned int serialNum, int index)
{
    currentIndex = index;
    currentSerialNum = serialNum;
    if (index == 0) {
            // CustomerInfo table
            if (!customerModel) {
                customerModel = new QSqlTableModel(this, dbe);
            }
            customerModel->setTable("CustomerInfo");
            customerModel->setFilter("ID = " + QString::number(currentSerialNum));
            customerModel->select();
            ui->tableView->setModel(customerModel);
        } else if (index == 1) {
            // ServiceInfo table
            if (!serviceModel) {
                serviceModel = new QSqlTableModel(this, dbe);
            }
            serviceModel->setTable("ServiceInfo");
            serviceModel->setFilter("ID = " + QString::number(currentSerialNum));
            serviceModel->select();
            ui->tableView->setModel(serviceModel);
    }
//    else if (index == 3){model->ProductEdit::loadData(serialNum);}
//    this->show();

}


void EditTable::on_pushButton_clicked()
{
    if (currentIndex == 0) {
        // CustomerInfo table update
        QString name = ui->tableView->model()->data(ui->tableView->model()->index(0, 1)).toString();
        int contactInfo = ui->tableView->model()->data(ui->tableView->model()->index(0, 2)).toInt();
        QString representName = ui->tableView->model()->data(ui->tableView->model()->index(0, 3)).toString();
        int product = ui->tableView->model()->data(ui->tableView->model()->index(0, 4)).toInt();

        QSqlQuery query(dbe);
        query.prepare("UPDATE CustomerInfo SET Name = ?, ContactInfo = ?, RepresentName = ?, Product = ? WHERE ID = ?");
        query.addBindValue(name);
        query.addBindValue(contactInfo);
        query.addBindValue(representName);
        query.addBindValue(product);
        query.addBindValue(currentSerialNum);

        bool success = query.exec();
        if (!success) {
            qDebug() << "Error in CustomerInfo update:" << query.lastError().text();
        } else {
//            qDebug() << "CustomerInfo updated successfully.";
        }
    } else {}/*if (currentIndex == 1) {
        // ServiceInfo table update
        QString date = ui->tableView->model()->data(ui->tableView->model()->index(0, 1)).toString();
        QString authority = ui->tableView->model()->data(ui->tableView->model()->index(0, 2)).toString();
        QString serviceType = ui->tableView->model()->data(ui->tableView->model()->index(0, 3)).toString();
        QString description = ui->tableView->model()->data(ui->tableView->model()->index(0, 4)).toString();
        QString impairedPart = ui->tableView->model()->data(ui->tableView->model()->index(0, 5)).toString();

        QSqlQuery query(db);
        query.prepare("UPDATE ServiceInfo SET Date = ?, Authority = ?, ServiceType = ?, Description = ?, ImpairedPart = ? WHERE ID = ?");
        query.addBindValue(date);
        query.addBindValue(authority);
        query.addBindValue(serviceType);
        query.addBindValue(description);
        query.addBindValue(impairedPart);
        query.addBindValue(currentSerialNum);

        bool success = query.exec();
        if (!success) {
            qDebug() << "Error in ServiceInfo update:" << query.lastError().text();
        } else {
//            qDebug() << "ServiceInfo updated successfully.";
        }
    } else if (currentIndex == 3) {
        // ProductInfo table update
        QString a[7]; // Adjust the size to 7 to match the columns count
        for (int i = 1; i < 7; i++) {
            a[i-1] = ui->tableView->model()->data(ui->tableView->model()->index(0, i)).toString();
        }
//        qDebug() << " 1: " + a[0] + " 2: " + a[1] + " 3: " + a[2] + " 4: " + a[3] + " 5: " + a[4] + " 6: " + a[5];

        QSqlQuery q(db);
        q.prepare("UPDATE ProductInfo SET ProductName = ?, Invoice = ?, AnyDeskNO = ? WHERE SerialNO = ?");
        q.addBindValue(a[0]);
        q.addBindValue(a[1].toInt()); // Assuming Invoice is an integer
        q.addBindValue(a[2].toInt()); // Assuming AnyDeskNO is an integer
        q.addBindValue(currentSerialNum);

        bool er = q.exec();
        if (!er) {
            qDebug() << "Error in ProductInfo update:" << q.lastError().text();
        }

        q.prepare("UPDATE ProductSecInfo SET GuarantyExp = ?, PurchaseDate = ?, Description = ? WHERE SerialNO = ?");
        q.addBindValue(a[3]);
        q.addBindValue(a[4]);
        q.addBindValue(a[5]);
        q.addBindValue(currentSerialNum);

        bool err = q.exec();
        if (!err) {
//            qDebug() << "Error in ProductSecInfo update:" << q.lastError().text();
        }
    }*/
}






