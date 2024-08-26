//#include "requestform.h"
//#include "ui_requestform.h"
//#include "myfunctions.h"
//#include <QtDebug>
//#include <QSqlDatabase>
//#include <QSqlDriver>
//#include <QSqlQuery>
//#include <QSqlQueryModel>
//#include <QSqlError>



//RequestForm::RequestForm(QWidget *parent) :
//    QWidget(parent),
//    ui(new Ui::RequestForm)
//{
//    ui->setupUi(this);
////    QSqlDatabase dbrf;
////    dbrf = QSqlDatabase ::addDatabase("QSQLITE");
////    dbrf.setDatabaseName("C:\\Users\\kiafa\\Desktop\\Job\\DB\\sqlitestudio_x64-3.4.4\\SQLiteStudio\\InfoDB");
////    dbrf.open();
//}
//void RequestForm::addTrigger(){
//    this->show();
//}

//RequestForm::~RequestForm()
//{
//    delete ui;
//}


//void RequestForm::on_pushButton_clicked()
//{
//    QString checks = "";

//    if(ui ->checkBox ->isChecked()) {
//        checks = checks+"1";

//    }
//    else checks = checks+"0";
//    if(ui ->checkBox_2 ->isChecked()) {
//        checks = checks+"1";

//    }
//    else checks = checks+"0";
//    if(ui ->checkBox_3 ->isChecked()) {
//        checks = checks+"1";

//    }
//    else checks = checks+"0";
//    if(ui ->checkBox_4 ->isChecked()) {
//        checks = checks+"1";

//    }
//    else checks = checks+"0";
//    if(ui ->checkBox_5 ->isChecked()) {
//        checks = checks+"1";

//    }
//    else checks = checks+"0";
//    if(ui ->checkBox_6 ->isChecked()) {
//        checks = checks+"1";

//    }
//    else checks = checks+"0";
//    if(ui ->checkBox_7 ->isChecked()) {
//        checks = checks+"1";

//    }
//    else checks = checks+"0";
//    if(ui ->checkBox_8 ->isChecked()) {
//        checks = checks+"1";

//    }
//    else checks = checks+"0";
//    if(ui ->checkBox_9 ->isChecked()) {
//        checks = checks+"1";

//    }
//    else checks = checks+"0";
//    if(ui ->checkBox_10 ->isChecked()) {
//        checks = checks+"1";

//    }
//    else checks = checks+"0";
//    ;
//    if(ui ->checkBox_11 ->isChecked()) {
//        checks = checks+"1";

//    }
//    else checks = checks+"0";
//    if(ui ->checkBox_12 ->isChecked()) {
//        checks = checks+"1";

//    }
//    else checks = checks+"0";
//    if(ui ->checkBox_13 ->isChecked()) {
//        checks = checks+"1";

//    }
//    else checks = checks+"0";
//    if(ui ->checkBox_14 ->isChecked()) {
//        checks = checks+"1";

//    }
//    else checks = checks+"0";



//    QSqlQuery q(dbConnection.getConnection());
//    if ( MyFunctions::checkSN(ui->sn->text())){
//    QString realSN = ui->sn->text();
////    qDebug() <<  MyFunctions::reverseSN(realSN);
//    bool er = q.exec("INSERT INTO DeviceInfo VALUES ("+  MyFunctions::reverseSN(realSN) +", '" +ui->cell->text() +"', '" +ui->power->text()+"', '" +ui->charger->text()+"', '" +ui->battery->text()+"', '" +ui->board->text()+"', '" +ui->motherBoard->text()+"', '" +ui->memory->text()+"', "+QString::number(  MyFunctions::binaryToDecimal( checks)) +");" );
////    qDebug() <<     q.exec("INSERT INTO DeviceInfo VALUES ("+ ui->sn->text() +", " +ui->cell->text() +", " +ui->power->text()+", " +ui->charger->text()+", " +ui->battery->text()+", " +ui->board->text()+", " +ui->motherBoard->text()+", " +ui->memory->text()+", "+QString::number( secChecks) +");" );
//    if(!er){qDebug() << q.lastError().text();}
//    }
//}



