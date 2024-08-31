#include "productregister.h"
#include "ui_productregister.h"
#include "myfunctions.h"
#include <QtDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>



// Function to get or create the database connection


ProductRegister::ProductRegister(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProductRegister),
    db(DatabaseConnection::getInstance())
{
    ui->setupUi(this);
//    db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("C:\\Users\\kiafa\\Desktop\\Job\\DB\\sqlitestudio_x64-3.4.4\\SQLiteStudio\\InfoDB");
//    db.open();
}
QString Mode;
int Serialnum;
QString a[7];

ProductRegister::~ProductRegister()
{

    delete ui;
}

void ProductRegister::on_pushButton_clicked()
{


    if (Mode == "REGISTER") { regSubmit(); }
    else if (Mode == "EDIT") { editSubmit(); }
    else { qDebug() << "what is the mode?"; }
}

void ProductRegister::regOn() { Mode = "REGISTER"; }

void ProductRegister::regSubmit()
{


    if (MyFunctions::checkSN(ui->lineEdit_8->text())) {
        a[0] = MyFunctions::reverseSN(ui->lineEdit_8->text());
        a[1] = ui->lineEdit_9->text();
        a[2] = ui->lineEdit_10->text();
        a[3] = ui->lineEdit_11->text();
        a[4] = ui->lineEdit_12->text();
        a[5] = ui->lineEdit_13->text();
        a[6] = ui->textEdit->toPlainText();

//        qDebug() << " 1: " + a[0] + " 2: " + a[1] + " 3: " + a[2] + " 4: " + a[3] + " 5: " + a[4] + " 6: " + a[5] + " 7: " + a[6];

        // Call register functions here
        registerProductInfo();
        registerProductSecInfo();
    } else {
        qDebug() << "incorrect serial number";
    }
}

void ProductRegister::editOn(int Serial) {
    Mode = "EDIT";
    Serialnum = Serial;
}

void ProductRegister::editSubmit()
{


    a[0] = MyFunctions::reverseSN(ui->lineEdit_8->text());
    a[1] = ui->lineEdit_9->text();
    a[2] = ui->lineEdit_10->text();
    a[3] = ui->lineEdit_11->text();
    a[4] = ui->lineEdit_12->text();
    a[5] = ui->lineEdit_13->text();
    a[6] = ui->textEdit->toPlainText();

//    qDebug() << " 1: " + a[0] + " 2: " + a[1] + " 3: " + a[2] + " 4: " + a[3] + " 5: " + a[4] + " 6: " + a[5];

    updateProductInfo();
    updateProductSecInfo();
}

void ProductRegister::setup() {
    if (Mode == "REGISTER") {
        ui->lineEdit_8->setReadOnly(false);
        ui->lineEdit_9->setText("");
        ui->lineEdit_10->setText("");
        ui->lineEdit_11->setText("");
        ui->lineEdit_12->setText("");
        ui->lineEdit_13->setText("");
        ui->textEdit->setText("");
    } else if (Mode == "EDIT") {
        ui->lineEdit_8->setReadOnly(false);
        ui->lineEdit_8->setText(MyFunctions::intToStr(Serialnum));
        ui->lineEdit_8->setReadOnly(true);

        loadProductInfo();
        loadProductSecInfo();
    }
    this->show();
}

void ProductRegister::loadProductInfo(){


    QSqlQuery query(db.getConnection());
    query.prepare("SELECT * FROM ProductInfo WHERE SerialNO = :serialNumber");
    query.bindValue(":serialNumber", QString::number(Serialnum));
//    qDebug() << "Executing query for ProductInfo with Serialnum:" << Serialnum;

    if (!query.exec()) {
        qDebug() << "Database query error:" << query.lastError().text();
    } else {
        if (query.next()) {
            ui->lineEdit_9->setText(query.value("ProductName").toString());
            ui->lineEdit_10->setText(query.value("Invoice").toString());
            ui->lineEdit_11->setText(query.value("AnyDeskNO").toString());
        } else {
            qDebug() << "No data found for serial number:" << Serialnum;
        }
    }
}

void ProductRegister::loadProductSecInfo(){


    QSqlQuery query(db.getConnection());
    query.prepare("SELECT * FROM ProductSecInfo WHERE SerialNO = :serialNumber");
    query.bindValue(":serialNumber", QString::number(Serialnum));
//    qDebug() << "Executing query for ProductSecInfo with Serialnum:" << Serialnum;

    if (!query.exec()) {
        qDebug() << "Database query error:" << query.lastError().text();
    } else {
        if (query.next()) {
            ui->lineEdit_12->setText(query.value("GuarantyExp").toString());
            ui->lineEdit_13->setText(query.value("PurchaseDate").toString());
            ui->textEdit->setText(query.value("Description").toString());
        } else {
            qDebug() << "No data found for serial number:" << Serialnum;
        }
    }
}

void ProductRegister::trigger(int serialnum) {
//    qDebug() << "Serialnum set to:" << Serialnum; // Debugging statement
    editOn(serialnum);
    setup();
}

void ProductRegister::addTrigger() {
    regOn();
    setup();
}

void ProductRegister::updateProductInfo(){


    QSqlQuery q(db.getConnection());
    q.prepare("UPDATE ProductInfo SET ProductName = ?, Invoice = ?, AnyDeskNO = ? WHERE SerialNO = ?");
    q.addBindValue(a[1]);
    q.addBindValue(a[2]);
    q.addBindValue(a[3]);
    q.addBindValue(a[0]);

    bool er = q.exec();
    if (!er) {
        qDebug() << "Error in ProductInfo update:" << q.lastError().text();
    } else {
//        qDebug() << "success 1 " + a[0];
    }
}

void ProductRegister::updateProductSecInfo(){

    QSqlQuery qe(db.getConnection());
    qe.prepare("UPDATE ProductSecInfo SET GuarantyExp = ?, PurchaseDate = ?, Description = ? WHERE SerialNO = ?");
    qe.addBindValue(a[4]);
    qe.addBindValue(a[5]);
    qe.addBindValue(a[6]);
    qe.addBindValue(a[0]);

    bool err = qe.exec();
    if (!err) {
        qDebug() << "Error in ProductSecInfo update:" << qe.lastError().text();
    } else {
//        qDebug() << "success 2";
    }

}

void ProductRegister::registerProductInfo(){


    QSqlQuery q(db.getConnection());
    q.prepare("INSERT INTO ProductInfo (SerialNO, ProductName, Invoice, AnyDeskNO) VALUES (?, ?, ?, ?)");
    q.addBindValue(a[0]);
    q.addBindValue(a[1]);
    q.addBindValue(a[2]);
    q.addBindValue(a[3]);

    bool er = q.exec();
    if (!er) {
        qDebug() << "Error in ProductInfo insert:" << q.lastError().text();
    }
}

void ProductRegister::registerProductSecInfo(){


    QSqlQuery q(db.getConnection());
    q.prepare("INSERT INTO ProductSecInfo (SerialNO, GuarantyExp, PurchaseDate, Description) VALUES (?, ?, ?, ?)");
    q.addBindValue(a[0]);
    q.addBindValue(a[4]);
    q.addBindValue(a[5]);
    q.addBindValue(a[6]);

    bool err = q.exec();
    if (!err) {
        qDebug() << "Error in ProductSecInfo insert:" << q.lastError().text();
    }
}
