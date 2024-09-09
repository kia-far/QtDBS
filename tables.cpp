#include "tables.h"
#include "ui_tables.h"
#include "myfunctions.h"
#include "mainwindow.h"
#include "MyTableProxy.h"
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QtDebug>
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QAction>

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
//    MyTableProxy(new MyTableProxy(this)),
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
    qDebug() << "loadDevice result :"<<ItemHandler::loadDevices();
    QFile file("C:/Users/kiafa/Documents/build-QtDBS-Desktop_Qt_5_12_12_MinGW_64_bit-Debug/style/Style.qss"); // Use resource system or provide a direct path
    if (file.open(QFile::ReadOnly)) {
        QTextStream stream(&file);
        QString styleSheet = stream.readAll();
        this->setStyleSheet(styleSheet);
        file.close();
        keybinds();
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
    if (table == "محصولات"){
//        qDebug () << "product opened -------------------------------";
        currentTable = 3;
        ui->comboBox->setCurrentIndex(currentTable);
        ui->tableView->setModel(Product);

    }
    else if(table == "دستگاه ها") {
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
    else if(table == "خدمات") {
//        qDebug () << "service opened -------------------------------";
        QSqlQuery q(db.getConnection());
        q.exec("SELECT * FROM ServiceInfo");
        QSqlQueryModel *m = new QSqlQueryModel;
        m -> setQuery(q);

        currentTable =1;
        ui->comboBox->setCurrentIndex(currentTable);
        ui->tableView->setModel(m);

    }
    else if(table == "مشتریان") {
//        qDebug () << "customer opened -------------------------------";
//        QSqlQuery q(db.getConnection());
//        q.exec("SELECT * FROM CustomerInfo");
//        QSqlQueryModel *m = new QSqlQueryModel;
//        m -> setQuery(q);
//        currentTable = 0;
//        ui->comboBox->setCurrentIndex(currentTable);
//        ui->tableView->setModel(m);
//+++++++++++++++++++++++++
        QStringList columnNames = {"شناسه", "نام", "شماره تماس", "نام نماینده"}; // Example list
        QSqlDatabase a = (db.getConnection());
        MyTableProxy *Customer = new MyTableProxy(columnNames,a,this);
        Customer->loadData("SELECT * FROM CustomerInfo");
        ui->tableView->setModel(Customer);

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
        QStringList columnNames = {"شناسه", "نام", "شماره تماس", "نام نماینده"}; // Example list
        QSqlDatabase a = (db.getConnection());
        MyTableProxy *Customer = new MyTableProxy(columnNames,a,this);
        Customer->loadData(res);
        ui->tableView->setModel(Customer);


    }
    else if (currentTable==1) {
        QSqlQuery query(db.getConnection());
        QString res;
        if(searchText==""){res = "SELECT * FROM ServiceInfo";}
        else{res = "SELECT * FROM ServiceInfo WHERE "+searchParam+" LIKE '%"+searchText+"%'";}
        query.exec(res);
//        QSqlQueryModel *m = new QSqlQueryModel;
//        m -> setQuery(query);
//        ui->tableView->setModel(m);

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
    if(arg1 == "محصولات"){
        ui->tableView->setModel(Product);


        currentTable =3;
    }
    else if(arg1 == "مشتریان"){
        QStringList columnNames = {"شناسه", "نام", "شماره تماس", "نام نماینده"}; // Example list
        QSqlDatabase a = (db.getConnection());
        MyTableProxy *Customer = new MyTableProxy(columnNames,a,this);
        Customer->loadData("SELECT * FROM CustomerInfo");
        ui->tableView->setModel(Customer);
        currentTable =0;
    }
    else if (arg1 == "خدمات"){
        QSqlQuery q(db.getConnection());
        q.exec("SELECT * FROM ServiceInfo");
        QSqlQueryModel *m = new QSqlQueryModel;
        m -> setQuery(q);
        ui->tableView->setModel(m);
        currentTable =1;
    }
    else if (arg1 == "دستگاه ها") {
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
    if(arg1 == "new"){

    }
    else{
    currentDevice = arg1;
    QString searchParam = "SerialNumber";
    QString searchText = "";
    View->setSearchParameters(currentDevice,searchParam, searchText);
    ui->tableView->setModel(View);
}}


void Tables::on_tableView_doubleClicked(const QModelIndex &index)
{
    if (currentTable == 0){emit editCustomer(clickedID);}
    else if (currentTable == 1){emit editService(clickedID);}
    else if (currentTable == 2){emit editDevice(currentDevice,lastClicked);}
    else {emit editProduct(lastClicked );}
}

void Tables::keybinds(){
    QAction *f0 = new QAction(this);
    f0->setShortcut(Qt::Key_Q | Qt::CTRL);

    connect(f0, SIGNAL(triggered()), this, SLOT(on_mainWindowBtn_clicked()));
    this->addAction(f0);
    QAction *f1 = new QAction(this);
    f1->setShortcut(Qt::Key_R | Qt::CTRL);

    connect(f1, SIGNAL(triggered()), this, SLOT(on_RefreshBtn_clicked()));
    this->addAction(f1);
    QAction *f2 = new QAction(this);
    f2->setShortcut(Qt::Key_F | Qt::CTRL);

    connect(f2, SIGNAL(triggered()), this, SLOT(on_SearchBtn_clicked()));
    this->addAction(f2);
    QAction *f3 = new QAction(this);
    f3->setShortcut(Qt::Key_N | Qt::CTRL);

    connect(f3, SIGNAL(triggered()), this, SLOT(on_AddBtn_clicked()));
    this->addAction(f3);
//    QAction *f4 = new QAction(this);
//    f4->setShortcut(Qt::Key_P | Qt::CTRL);

//    connect(f4, SIGNAL(triggered()), this, SLOT(on_comboBox_currentIndexChanged()));
//    this->addAction(f4);
//    QAction *f5 = new QAction(this);
//    f5->setShortcut(Qt::Key_C | Qt::CTRL);

//    connect(f5, SIGNAL(triggered()), this, SLOT(on_comboBox_currentIndexChanged("Customers")));
//    this->addAction(f5);
//    QAction *f6 = new QAction(this);
//    f6->setShortcut(Qt::Key_S | Qt::CTRL);

//    connect(f6, SIGNAL(triggered()), this, SLOT(on_comboBox_currentIndexChanged("Services")));
//    this->addAction(f6);
}
