#include "tables.h"
#include "ui_tables.h"
#include "myfunctions.h"
#include "mainwindow.h"
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QtDebug>
#include <QApplication>
#include <QFile>
#include <QTextStream>


int lastClicked =0;
int currentTable =0;
int editSelect =0;
int clickedID =0;
//bool inSearch=false;
QString searchParam;

Tables::Tables(MainWindow *mainWin,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tables),
    View(new ProxyView(this)),
    Product(new ProductProxy(this)),
    db(DatabaseConnection::getInstance()),
    mainwindow(mainWin)

{

    ui->setupUi(this);
//    ui->Edit->hide();
//    QSqlDatabase db;
//    db = QSqlDatabase ::addDatabase("QSQLITE");
//    db.setDatabaseName("C:\\Users\\kiafa\\Desktop\\Job\\DB\\sqlitestudio_x64-3.4.4\\SQLiteStudio\\InfoDB");
//    db.open();
    ui->comboBox_2->addItems(ItemHandler::loadDevices());
    QFile file("C:/Users/kiafa/Documents/build-QtDBS-Desktop_Qt_5_12_12_MinGW_64_bit-Debug/style/Style.qss"); // Use resource system or provide a direct path
    if (file.open(QFile::ReadOnly)) {
        QTextStream stream(&file);
        QString styleSheet = stream.readAll();
        this->setStyleSheet(styleSheet);
        file.close();
    }

    ui->tableView->setAlternatingRowColors(true);
//    currentTable = 3;
}

Tables::~Tables()
{
    delete ui;
}

void Tables::setupTable(QString table){
    ui->comboBox_2->hide();
    if (table == "product"){
//        qDebug () << "product opened -------------------------------";
        currentTable = 3;
        ui->comboBox->setCurrentIndex(currentTable);
        ui->tableView->setModel(Product);

    }
    else if(table == "device") {
        ui->comboBox_2->show();
        currentDevice=ui->comboBox_2->currentText();
//        qDebug () << "device opened -------------------------------";
        QString searchParam = "SerialNumber";
        QString searchText = "";
        View->setSearchParameters(currentDevice,searchParam, searchText);
        currentTable = 2;
        ui->comboBox->setCurrentIndex(currentTable);
        ui->tableView->setModel(View);
    }
    else if(table == "service") {
//        qDebug () << "service opened -------------------------------";
        QSqlQuery q(db.getConnection());
        q.exec("SELECT * FROM ServiceInfo");
        QSqlQueryModel *m = new QSqlQueryModel;
        m -> setQuery(q);
        currentTable =1;
        ui->comboBox->setCurrentIndex(currentTable);
        ui->tableView->setModel(m);

    }
    else if(table == "customer") {
//        qDebug () << "customer opened -------------------------------";
        QSqlQuery q(db.getConnection());
        q.exec("SELECT * FROM CustomerInfo");
        QSqlQueryModel *m = new QSqlQueryModel;
        m -> setQuery(q);
        currentTable = 0;
        ui->comboBox->setCurrentIndex(currentTable);
        ui->tableView->setModel(m);


}
    else {qDebug() << "wrong input";}
    this->show();
}
void Tables::searchInfo(QString currentSearchParam,QString searchText){
    searchParam = currentSearchParam;
//    qDebug()<<QString::number(currentTable)+"  "  + "  "+ searchParam+ "   " +searchText;
    if(currentTable==0){





//        QSqlQuery query;
        QString res;
        if (searchText==""){res = "SELECT * FROM CustomerInfo";}
        else{res = "SELECT * FROM CustomerInfo WHERE "+searchParam+" LIKE '%"+searchText+"%'";}
        QSqlQuery query(db.getConnection());
        query.exec(res);
        QSqlQueryModel *m = new QSqlQueryModel;
        m -> setQuery(query);

        ui->tableView->setModel(m);

    }
    else if (currentTable==1) {
        QSqlQuery query(db.getConnection());
        QString res;
        if(searchText==""){res = "SELECT * FROM ServiceInfo";}
        else{res = "SELECT * FROM ServiceInfo WHERE "+searchParam+" LIKE '%"+searchText+"%'";}
        query.exec(res);
        QSqlQueryModel *m = new QSqlQueryModel;
        m -> setQuery(query);
        ui->tableView->setModel(m);

    }
    else if(currentTable==2){

        View->setSearchParameters(currentDevice,searchParam, searchText);
        ui->tableView->setModel(View);
    }
    else {
        Product->setSearchParameters(searchParam,searchText);
        ui->tableView->setModel(Product);
    }
}
void Tables::on_comboBox_currentIndexChanged(const QString &arg1)
{
    ui->comboBox_2->hide();
    if(arg1 == "Products"){
        ui->tableView->setModel(Product);


        currentTable =3;
    }
    else if(arg1 == "Customers"){
        QSqlQuery q(db.getConnection());
        q.exec("SELECT * FROM CustomerInfo");
        QSqlQueryModel *m = new QSqlQueryModel;
        m -> setQuery(q);
        ui->tableView->setModel(m);

        currentTable = 0;
    }
    else if (arg1 == "Services"){
        QSqlQuery q(db.getConnection());
        q.exec("SELECT * FROM ServiceInfo");
        QSqlQueryModel *m = new QSqlQueryModel;
        m -> setQuery(q);
        ui->tableView->setModel(m);
        currentTable =1;
    }
    else if (arg1 == "Devices") {
        ui->comboBox_2->show();
        currentDevice=ui->comboBox_2->currentText();
        QString searchParam = "SerialNumber";
        QString searchText = "";
        View->setSearchParameters(currentDevice,searchParam, searchText);

        ui->tableView->setModel(View);
        currentTable = 2;
    }
}


void Tables::on_EditBtn_clicked()
{
    if (currentTable == 0){emit editCustomer(clickedID);}
    else if (currentTable == 1){emit editService(clickedID);}
    else if (currentTable == 2){emit editDevice(currentDevice,lastClicked);}
    else {emit editProduct(lastClicked );}
}


void Tables::on_tableView_clicked(const QModelIndex &index)
{
    int selectedRow = index.row();
//    qDebug() << "Selected row:" << selectedRow;
    QVariant data = ui->tableView->model()->data(ui->tableView->model()->index(selectedRow, 0));
//    qDebug() << "Data in the first column of the selected row:" << data.toString();
    lastClicked = (MyFunctions ::reverseSN(data.toString())).toInt();
    clickedID = data.toInt();
}


void Tables::on_SearchBtn_clicked()
{
    emit searchActive(currentTable);
}


void Tables::on_AddBtn_clicked()
{
    if (currentTable==3){emit addProduct();}
    else if(currentTable==2){emit addDevice(currentDevice);}
    else if(currentTable==1){emit addService();}
    else{emit addCustomer();}
}


void Tables::on_RefreshBtn_clicked()
{
    emit refreshActive(currentTable);
}


void Tables::on_mainWindowBtn_clicked()
{
    this->hide();
    mainwindow->show();
}





void Tables::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    currentDevice = arg1;
    QString searchParam = "SerialNumber";
    QString searchText = "";
    View->setSearchParameters(currentDevice,searchParam, searchText);
    ui->tableView->setModel(View);
}


void Tables::on_tableView_doubleClicked(const QModelIndex &index)
{
    if (currentTable == 0){emit editCustomer(clickedID);}
    else if (currentTable == 1){emit editService(clickedID);}
    else if (currentTable == 2){emit editDevice(currentDevice,lastClicked);}
    else {emit editProduct(lastClicked );}
}

