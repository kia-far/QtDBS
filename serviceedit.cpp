#include "serviceedit.h"
#include "ui_serviceedit.h"
#include "myfunctions.h"
#include <QtDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QAction>
#include <QCalendar>

serviceEdit::serviceEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::serviceEdit),
    db(DatabaseConnection::getInstance())
{
    ui->setupUi(this);
    keyBinds();
    QDate minDate (1,1,1);
    // qDebug()<<QCalendar::;
    QDate maxDate(9999, 12, 31);
//    QJalaliCalendar
    //
    QCalendar calendar( QCalendar::System::Jalali);
    ui->dateEdit->setCalendar(calendar);
    ui->dateEdit->setDate(QDate::currentDate());
    //
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
void serviceEdit::regOn(){Modee = "REGISTER";setup(); }
void serviceEdit::editOn(unsigned int serial){
    Modee="EDIT";
    ID = serial;
}
void serviceEdit::regSubmit(){
    b[0] = ui->dateEdit->text();
    b[1]=ui->lineEdit_2->text();
    b[2]=ui->lineEdit_3->text();
    b[3]=ui->textEdit->toPlainText();
    b[4]=ui->lineEdit_5->text();
    b[5] = ui->CustomerCombo->currentText();
    b[6] = ui->ProductCombo->currentText();

    QSqlQuery query(db.getConnection());
    query.prepare("INSERT INTO ServiceInfo (Date , Authority , ServiceType , Description , ImpairedPart , Customer , Product) VALUES (?, ? , ? , ? , ? , ? , ?)");
    query.addBindValue(b[0]);
    query.addBindValue(b[1]);
    query.addBindValue(b[2]);
    query.addBindValue(b[3]);
    query.addBindValue(b[4]);
    query.addBindValue(b[5]);
    query.addBindValue(b[6]);

//    qDebug() << "Executing query for ProductInfo with Serialnum:" <<ID;

    if (!query.exec()) {
        qDebug() << "Database query error:" << query.lastError().text();
    }
    emit callPageRefresh();
}
void serviceEdit::editSubmit(){
    b[0] = QString::number(ID);
    b[1] = ui->dateEdit->text();
    b[2] = ui->lineEdit_2->text();
    b[3] = ui->lineEdit_3->text();
    b[4] = ui->textEdit->toPlainText();
    b[5] = ui->lineEdit_5->text();
    b[6] = ui->CustomerCombo->currentText();
    b[7] = ui->ProductCombo->currentText();
    QSqlQuery q(db.getConnection());
    q.prepare("UPDATE ServiceInfo SET Date = ?, Authority = ?, ServiceType = ?, Description = ?, ImpairedPart = ?, Customer = ?, Product = ? WHERE ID = ?");
    q.addBindValue(b[1]);
    q.addBindValue(b[2]);
    q.addBindValue(b[3]);
    q.addBindValue(b[4]);
    q.addBindValue(b[5]);
    q.addBindValue(b[6]);
    q.addBindValue(b[7]);
    q.addBindValue(b[0]);


    bool er = q.exec();
    if (!er) {
        qDebug() << "Error in ProductInfo update:" << q.lastError().text();
    } else {
//        qDebug() << "success 1 " + b[0];
    }
    emit callPageRefresh();

}
void serviceEdit::trigger(unsigned int serialnum){
    editOn(serialnum);
    ID  = serialnum;
    setup();
}
void serviceEdit::setup(){


    if (Modee == "REGISTER") {
        QCalendar calendar( QCalendar::System::Jalali);
        ui->dateEdit->setCalendar(calendar);
        ui->dateEdit->setDate(QDate::currentDate());
        ui->lineEdit_2->setText("");
        ui->lineEdit_3->setText("");
        ui->textEdit->setText("");
        ui->lineEdit_5->setText("");
        ui->CustomerCombo->setCurrentText("");
        ui->ProductCombo->setCurrentText("");
    } else if (Modee == "EDIT") {
        QSqlQuery query(db.getConnection());
        query.prepare("SELECT * FROM ServiceInfo WHERE ID = ?");
        query.addBindValue(ID);
        if (!query.exec()) {
            qDebug() << "Database query error:" << query.lastError().text();
        } else {
            if (query.next()) {
                QCalendar calendar(QCalendar::System::Jalali);
                ui->dateEdit->setCalendar(calendar);
                QString rt = query.value("Date").toString();
                QStringList parts = rt.split('/');
                if (parts.size() == 3) {
                    int year = parts[0].toInt();
                    int month = parts[1].toInt();
                    int day = parts[2].toInt();
                    QDate jalaliDate = QDate(year, month, day, calendar);
                    if (jalaliDate.isValid()) {
                        ui->dateEdit->setDate(jalaliDate);
                    } else {
                        qWarning() << "Invalid Jalali date!";
                    }
                } else {
                    qWarning() << "Invalid date format!";
                }
                ui->lineEdit_2->setText(query.value("Authority").toString());
                ui->lineEdit_3->setText(query.value("ServiceType").toString());
                ui->textEdit->setText(query.value("Description").toString());
                ui->lineEdit_5->setText(query.value("ImpairedPart").toString());
                ui->CustomerCombo->setCurrentText(query.value("Customer").toString());
                ui->ProductCombo->setCurrentText(query.value("Product").toString());

            } else {
                qDebug() << "No data found for ID: " << ID;
            }
        }
    }
    this->show();
}

void serviceEdit::keyBinds(){
    QAction *f0 = new QAction(this);
    f0->setShortcut(Qt::Key_Q | Qt::CTRL);

    connect(f0, SIGNAL(triggered()), this, SLOT(close()));
    this->addAction(f0);
    QAction *f1 = new QAction(this);
    f1->setShortcut(Qt::Key_S | Qt::CTRL);

    connect(f1, SIGNAL(triggered()), this, SLOT(on_pushButton_clicked()));
    this->addAction(f1);

}

void serviceEdit::populateCombo() {


}

QStringList serviceEdit::getCustomers(QString halfText){
    QSqlQuery query(db.getConnection());

    QStringList res;

    query.prepare("SELECT Name FROM CustomerInfo WHERE Name LIKE :halfText LIMIT 5");
    query.bindValue(":halfText", "%" + halfText + "%");  // Use wildcards for partial match

    // Execute the query
    if (query.exec()) {
        //        qDebug() << "Fetch the results";
        while (query.next()) {
            res << query.value(0).toString();  // Assuming 'name' is the first column
        }
    } else {
        qDebug() << "Query execution failed:" << query.lastError().text();
    }

    return res;
}

void serviceEdit::on_CustomerCombo_editTextChanged(const QString &arg1)
{
    ui->CustomerCombo->blockSignals(true);
    ui->CustomerCombo->clear();
    QStringList customers = getCustomers(arg1);
    ui->CustomerCombo->addItems(customers);
    ui->CustomerCombo->setCurrentText(arg1);
    ui->CustomerCombo->blockSignals(false);

}
//"SELECT SerialNO FROM ProductInfo WHERE SerialNO LIKE :halfText LIMIT 5"
QStringList serviceEdit::getProducts(QString halfText){
    QSqlQuery query(db.getConnection());

    QStringList res;
    if(!halfText.isEmpty()){
        QString exeQ = MyFunctions::searchHandler("SerialNO", "ProductInfo", "SerialNO", halfText);
    // if(halfText.at(0).toUpper() == "B"||halfText.at(0).toUpper() == "A"){
    //     QString devName = "";
    //     for(int i=9;i>halfText.length();i--){
    //         devName.append("_");
    //     }
    //     // qDebug () << MyFunctions::newReverseSN(halfText.toUpper()) + devName;

    //     if((MyFunctions::newReverseSN(halfText.toUpper()) + devName).length() == 10){
    //         devName = devName.remove(0,1);
    //     }
    //     qDebug () << MyFunctions::newReverseSN(halfText.toUpper()) + devName;
        exeQ.append(" LIMIT 5;");
        query.prepare(exeQ);

    //     query.prepare("SELECT SerialNO FROM ProductInfo WHERE SerialNO LIKE :halfText LIMIT 5");
    //     query.bindValue(":halfText", MyFunctions::newReverseSN(halfText.toUpper()) + devName);}  // Use wildcards for partial match    }
    // else{
    //     query.prepare("SELECT SerialNO FROM ProductInfo WHERE SerialNO LIKE :halfText LIMIT 5");
    //     query.bindValue(":halfText", MyFunctions::newReverseSN(halfText.toUpper()) + "%");  // Use wildcards for partial match
    //     // qDebug() << (MyFunctions::newReverseSN(halfText));
    //     // Execute the query
    //     }
    if (query.exec()) {
        //        qDebug() << "Fetch the results";
        while (query.next()) {
            res << MyFunctions::intToStr(query.value(0).toUInt());  // Assuming 'name' is the first column
        }
    } else {
        qDebug() << "Query execution failed:" << query.lastError().text();
    }

    return res;
}
    QStringList a = {};
    return (a);
}


void serviceEdit::on_ProductCombo_editTextChanged(const QString &arg1)
{
    ui->ProductCombo->blockSignals(true);
    ui->ProductCombo->clear();
    QStringList customers = getProducts(arg1);
    ui->ProductCombo->addItems(customers);
    ui->ProductCombo->setCurrentText(arg1);
    ui->ProductCombo->blockSignals(false);

}

