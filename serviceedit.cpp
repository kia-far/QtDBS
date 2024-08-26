#include "serviceedit.h"
#include "ui_serviceedit.h"
#include "myfunctions.h"
#include <QtDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>


serviceEdit::serviceEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::serviceEdit)
{
    ui->setupUi(this);

//    db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("C:\\Users\\kiafa\\Desktop\\Job\\DB\\sqlitestudio_x64-3.4.4\\SQLiteStudio\\InfoDB");
//    db.open();
}

serviceEdit::~serviceEdit()
{
    delete ui;
}

void serviceEdit::on_pushButton_clicked()
{

    if (Modee == "REGISTER") { regSubmit(); }
    else if (Modee == "EDIT") { editSubmit(); }
    else { qDebug() << "what is the mode?"; }
}
void serviceEdit::regOn(){Modee = "REGISTER";this->show();}
void serviceEdit::editOn(int serial){
    Modee="EDIT";
    ID = serial;
}
void serviceEdit::regSubmit(){
    b[0]=ui->lineEdit->text();
    b[1]=ui->lineEdit_2->text();
    b[2]=ui->lineEdit_3->text();
    b[3]=ui->lineEdit_4->text();
    b[4]=ui->lineEdit_5->text();

    QSqlQuery query(dbConnection.getConnection());
    query.prepare("INSERT INTO ServiceInfo (Date , Authority , ServiceType , Description , ImpairedPart) VALUES ( ? , ? , ? , ? , ?)");
    query.addBindValue(b[0]);
    query.addBindValue(b[1]);
    query.addBindValue(b[2]);
    query.addBindValue(b[3]);
    query.addBindValue(b[4]);

    qDebug() << "Executing query for ProductInfo with Serialnum:" <<ID;

    if (!query.exec()) {
        qDebug() << "Database query error:" << query.lastError().text();
    }
}
void serviceEdit::editSubmit(){
    b[0] = QString::number(ID);
    b[1] = ui->lineEdit->text();
    b[2] = ui->lineEdit_2->text();
    b[3] = ui->lineEdit_3->text();
    b[4] = ui->lineEdit_4->text();
    b[5] = ui->lineEdit_5->text();
    QSqlQuery q(dbConnection.getConnection());
    q.prepare("UPDATE ServiceInfo SET Date = ?, Authority = ?, ServiceType = ?, Description = ?, ImpairedPart = ? WHERE ID = ?");
    q.addBindValue(b[1]);
    q.addBindValue(b[2]);
    q.addBindValue(b[3]);
    q.addBindValue(b[4]);
    q.addBindValue(b[5]);
    q.addBindValue(b[0]);


    bool er = q.exec();
    if (!er) {
        qDebug() << "Error in ProductInfo update:" << q.lastError().text();
    } else {
        qDebug() << "success 1 " + b[0];
    }


}
void serviceEdit::trigger(int serialnum){
    editOn(serialnum);
    ID  = serialnum;
    setup();
}
void serviceEdit::setup(){


    if (Modee == "REGISTER") {
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
        ui->lineEdit_3->setText("");
        ui->lineEdit_4->setText("");
        ui->lineEdit_5->setText("");
    } else if (Modee == "EDIT") {
        QSqlQuery query(dbConnection.getConnection());
        query.prepare("SELECT * FROM ServiceInfo WHERE ID = ?");
        query.addBindValue(ID);
        if (!query.exec()) {
            qDebug() << "Database query error:" << query.lastError().text();
        } else {
            if (query.next()) {
                ui->lineEdit->setText(query.value("Date").toString());
                ui->lineEdit_2->setText(query.value("Authority").toString());
                ui->lineEdit_3->setText(query.value("ServiceType").toString());
                ui->lineEdit_4->setText(query.value("Description").toString());
                ui->lineEdit_5->setText(query.value("ImpairedPart").toString());

            } else {
                qDebug() << "No data found for ID: " << ID;
            }
        }
    }
    this->show();
}


