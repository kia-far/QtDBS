#include "customerform.h"
#include "ui_customerform.h"
#include "myfunctions.h"
#include <QtDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>



CustomerForm::CustomerForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomerForm),
    db(DatabaseConnection::getInstance())
{
    ui->setupUi(this);

}

CustomerForm::~CustomerForm()
{
    delete ui;
}

void CustomerForm::on_pushButton_clicked()
{

    if (Modee == "REGISTER") { regSubmit(); }
    else if (Modee == "EDIT") { editSubmit(); }
    else { qDebug() << "what is the mode?"; }
}
void CustomerForm::regOn(){Modee = "REGISTER";setup();}
void CustomerForm::editOn(int serial){
    Modee="EDIT";
    ID = serial;
}
void CustomerForm::regSubmit(){
    b[0]=ui->lineEdit->text();
    b[1]=ui->lineEdit_2->text();
    b[2]=ui->lineEdit_3->text();
    b[3]=ui->lineEdit_4->text();

    QSqlQuery query(db.getConnection());
    query.prepare("INSERT INTO CustomerInfo (Name , ContactInfo , RepresentName) VALUES ( ? , ? , ?)");
    query.addBindValue(b[1]);
    query.addBindValue(b[2]);
    query.addBindValue(b[3]);

    qDebug() << "Executing query for CustomerInfo with ID:" <<ID;

    if (!query.exec()) {
        qDebug() << "Database query error:" << query.lastError().text();
    }
}
void CustomerForm::editSubmit(){
    b[0] = QString::number(ID);
    b[1] = ui->lineEdit_2->text();
    b[2] = ui->lineEdit_3->text();
    b[3] = ui->lineEdit_4->text();
    QSqlQuery q(db.getConnection());
    q.prepare("UPDATE CustomerInfo SET Name = ?, ContactInfo = ?, RepresentName = ? WHERE ID = ?");
    q.addBindValue(b[1]);
    q.addBindValue(b[2]);
    q.addBindValue(b[3]);
    q.addBindValue(b[0]);


    bool er = q.exec();
    if (!er) {
        qDebug() << "Error in CustomerInfo update:" << q.lastError().text();
    } else {
        qDebug() << "success 1 " + b[0];
    }


}
void CustomerForm::trigger(int serialnum){
    editOn(serialnum);
    ID  = serialnum;
    setup();
}
void CustomerForm::setup(){


    if (Modee == "REGISTER") {
        QSqlQuery query(db.getConnection());
        query.prepare("SELECT MAX(ID) FROM CustomerInfo");
        if (!query.exec()) {
            qDebug() << "Database query error:" << query.lastError().text();
        } else {
            if (query.next()) {
                ui->lineEdit->setText(QString::number(query.value(0).toInt()+1));}}
        ui->lineEdit_2->setText("");
        ui->lineEdit_3->setText("");
        ui->lineEdit_4->setText("");
    } else if (Modee == "EDIT") {
        QSqlQuery query(db.getConnection());
        query.prepare("SELECT * FROM CustomerInfo WHERE ID = ?");
        query.addBindValue(ID);
        if (!query.exec()) {
            qDebug() << "Database query error:" << query.lastError().text();
        } else {
            if (query.next()) {
                ui->lineEdit->setText(QString::number(ID));
                ui->lineEdit_2->setText(query.value("Name").toString());
                ui->lineEdit_3->setText(query.value("ContactInfo").toString());
                ui->lineEdit_4->setText(query.value("RepresentName").toString());

            } else {
                qDebug() << "No data found for ID: " << ID;
            }
        }
    }
    this->show();
}