#include "serviceedit.h"
#include "ui_serviceedit.h"
#include "myfunctions.h"
#include <QtDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QAction>
#include <QCalendar>
#include <QCompleter>
#include <QAbstractItemView>
#include <itemhandler.h>
#include <QKeyEvent>

serviceEdit::serviceEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::serviceEdit),
    db(DatabaseConnection::getInstance())
{
    ui->setupUi(this);
    cCompleter = nullptr;
    pCompleter = nullptr;
    keyBinds();
    QDate minDate (1,1,1);
    populateCombo();
    // qDebug()<<QCalendar::;
    QDate maxDate(9999, 12, 31);
//    QJalaliCalendar
    //
    QCalendar calendar( QCalendar::System::Jalali);
    ui->dateEdit->setCalendar(calendar);
    ui->dateEdit->setDate(QDate::currentDate());
    // connect(ui->CustomerCombo,SIGNAL(activated(QString)),this,SLOT(onCustomerComboActivated(QString)));
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
    b[0] = MyFunctions::convertToEnglishString( ui->dateEdit->text());
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
    this->close();
}
void serviceEdit::editSubmit(){
    b[0] = QString::number(ID);
    b[1] = MyFunctions::convertToEnglishString( ui->dateEdit->text());
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
    this->close();

}
void serviceEdit::showHelpPop(){
    emit callHelpPop("لیست میانبر ها : \n CTRL + Q => بستن صفحه\n CTRL + S => ثبت کردن");
}
void serviceEdit::trigger(unsigned int serialnum){
    editOn(serialnum);
    ID  = serialnum;
    setup();
}
void serviceEdit::setup(){

    populateCombo();
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
    this->activateWindow();

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
    QAction *f2 = new QAction(this);
    f2->setShortcut(Qt::Key_F1);
    connect(f2, SIGNAL(triggered()),this, SLOT(showHelpPop()));
    this->addAction(f2);
}

void serviceEdit::populateCombo() {
    // QString arg2 = arg1.toUpper();
    // ui->ProductCombo->blockSignals(true);
    // ui->ProductCombo->setCurrentText(arg2);
    // ui->ProductCombo->clear();
    products = getProducts("");
    if(!(pCompleter==nullptr)){
        delete pCompleter;}
    pCompleter = new QCompleter(products);
    pCompleter->popup()->setStyleSheet("font-size: 20px");
    connect(pCompleter,SIGNAL(activated(QString)),this,SLOT(onProductComboCurrentTextChanged(QString)));
    ui->ProductCombo->setCompleter(pCompleter);
    qDebug() << products.length();
    // ui->ProductCombo->blockSignals(false);

    // ui->CustomerCombo->blockSignals(true);
    // ui->CustomerCombo->clear();
    customers = getCustomers("");
    if(!(cCompleter==nullptr)){
        delete cCompleter;}
    cCompleter = new QCompleter(customers);
    cCompleter->popup()->setStyleSheet("font-size: 20px");
    ui->CustomerCombo->setCompleter(cCompleter);
    connect(cCompleter,SIGNAL(activated(QString)),this,SLOT(onCustomerComboActivated(QString)));
    ui->ProductCombo->setCompleter(pCompleter);
    // ui->CustomerCombo->addItems(customers);
    // ui->CustomerCombo->setCurrentText(arg1);
    // ui->CustomerCombo->blockSignals(false);

}

QStringList serviceEdit::getCustomers(QString halfText){
    QSqlQuery query(db.getConnection());

    QStringList res;
    if(halfText==""){
        query.prepare("SELECT Name FROM CustomerInfo WHERE Name LIKE :halfText");
        query.bindValue(":halfText", "" + halfText + "%");  // Use wildcards for partial match

        // Execute the query
        if (query.exec()) {
            //        qDebug() << "Fetch the results";
            while (query.next()) {
                res << query.value(0).toString();  // Assuming 'name' is the first column
            }
        } else {
            qDebug() << "Query execution failed:" << query.lastError().text();
        }
    }
    else{
        QStringList devs = ItemHandler::loadDevices();
        for(QString dev : devs){
            query.prepare("SELECT CustomerName FROM "+ dev +" WHERE SerialNumber LIKE "+halfText);
            if (query.exec()) {
                //        qDebug() << "Fetch the results";
                while (query.next()) {
                    res << query.value(0).toString();  // Assuming 'name' is the first column
                }
            } else {
                qDebug() << "Query execution failed:" << query.lastError().text();
            }
        }
    }
    return res;
}

QStringList serviceEdit::getProducts(QString halfText){
    QSqlQuery query(db.getConnection());
    QStringList res;
    if(halfText==""){
        QString exeQ = MyFunctions::searchHandler("SerialNO", "ProductInfo", "SerialNO", halfText);
        query.prepare(exeQ);
        if (query.exec()) {
            while (query.next()) {
                res << MyFunctions::intToStr(query.value(0).toUInt());
            }
        } else {
            qDebug() << "Query execution failed:" << query.lastError().text();
        }
    }
    else{
        QStringList devs = ItemHandler::loadDevices();
        for(QString dev : devs){
            // qDebug() << "device :" << dev;
            query.prepare(QString("SELECT SerialNumber FROM %1 WHERE CustomerName LIKE ?;").arg(dev));
            query.addBindValue(halfText);
            // query.addBindValue(halfText);
            qDebug() << dev<<halfText;
            if (query.exec()) {
                       qDebug() << "Fetch the results"<<halfText;
                while (query.next()) {
                    res << MyFunctions::intToStr( query.value(0).toString().toUInt());  // Assuming 'name' is the first column
                    qDebug() << "query.value(0)" << query.value(0).toString();
                }
            } else {
                qDebug() << "Query execution failed:" << query.lastError().text();
            }
        }
    }
    qDebug() << "ran getProducts ";
    return res;
}


void serviceEdit::on_ProductCombo_editTextChanged(const QString &arg1)
{
    ui->ProductCombo->setCurrentText(arg1.toUpper());
}
void serviceEdit::onProductComboCurrentTextChanged( const QString &text){
    qDebug() << text;
    if(!text.isEmpty()){
        qDebug () << "2000";
        if(MyFunctions::checkData(MyFunctions::reverseSN(text),"SerialNO","ProductInfo")){
            ui->CustomerCombo->blockSignals(true);
            ui->CustomerCombo->setCurrentText(getCustomers(MyFunctions::reverseSN( text)).at(0));
            ui->CustomerCombo->blockSignals(false);
        }
    }
}

void serviceEdit::on_ProductCombo_activated(int index)
{
}

void serviceEdit::on_CustomerCombo_editTextChanged(const QString &arg1)
{
    ui->CustomerCombo->setCurrentText(arg1.toUpper());
    ui->CustomerCombo->clear();
    if(!(pCompleter==nullptr)){delete pCompleter;}
    pCompleter = new QCompleter(products);
    pCompleter->popup()->setStyleSheet("font-size: 20px");
    ui->ProductCombo->setCompleter(pCompleter);
    connect(pCompleter,SIGNAL(activated(QString)),this,SLOT(onProductComboCurrentTextChanged(QString)));
}

void serviceEdit::onCustomerComboActivated(const QString &text)
{
    if(MyFunctions::checkData(text,"Name","CustomerInfo")){
        // ui->ProductCombo->setCurrentText("hi");
        QStringList products = getProducts(text);
        // qDebug()<<products;
        ui->ProductCombo->clear();
        ui->ProductCombo->addItems(products);
        // QCompleter *pCompleter = new QCompleter(products);
        // pCompleter->popup()->setStyleSheet("font-size: 20px");
        // ui->ProductCombo->setCompleter(pCompleter);
        // qDebug() << products.length();
    }
}

void serviceEdit::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter){
        bool moved = this->focusNextChild();
        if (moved) {
            qDebug() << "Moved focus to the next widget.";
        }

        // Mark the event as accepted
        event->accept();
    }
    else{}
}
