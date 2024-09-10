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
void serviceEdit::editOn(int serial){
    Modee="EDIT";
    ID = serial;
}
void serviceEdit::regSubmit(){
    b[0] = ui->dateEdit->text();
    b[1]=ui->lineEdit_2->text();
    b[2]=ui->lineEdit_3->text();
    b[3]=ui->textEdit->toPlainText();
    b[4]=ui->lineEdit_5->text();

    QSqlQuery query(db.getConnection());
    query.prepare("INSERT INTO ServiceInfo (Date , Authority , ServiceType , Description , ImpairedPart) VALUES ( ? , ? , ? , ? , ?)");
    query.addBindValue(b[0]);
    query.addBindValue(b[1]);
    query.addBindValue(b[2]);
    query.addBindValue(b[3]);
    query.addBindValue(b[4]);

//    qDebug() << "Executing query for ProductInfo with Serialnum:" <<ID;

    if (!query.exec()) {
        qDebug() << "Database query error:" << query.lastError().text();
    }
}
void serviceEdit::editSubmit(){
    b[0] = QString::number(ID);
    b[1] = ui->dateEdit->text();
    b[2] = ui->lineEdit_2->text();
    b[3] = ui->lineEdit_3->text();
    b[4] = ui->textEdit->toPlainText();
    b[5] = ui->lineEdit_5->text();
    QSqlQuery q(db.getConnection());
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
//        qDebug() << "success 1 " + b[0];
    }


}
void serviceEdit::trigger(int serialnum){
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

