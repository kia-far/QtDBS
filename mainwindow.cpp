#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIcon>
#include <QDebug>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , tables(new Tables(this))
    , db(DatabaseConnection::getInstance())
{
    ui->setupUi(this);

    // qDebug() << ItemHandler::loadDevices();
    // qDebug() << "reverseSN" << MyFunctions::reverseSN("B00n8892");
    this->show();
    QObject::connect(x, &Tables::edit, &e, &EditTable::receiveTableIndex);
    QObject::connect(x, &Tables::searchActive, &r, &SearchForm::receiveTableIndex);
    QObject::connect(&r, &SearchForm::searchWorking, x, &Tables::searchInfo);
    QObject::connect(x, &Tables::editProduct,&b, &ProductRegister::trigger);
    QObject::connect(x, &Tables::refreshActive, &r, &SearchForm::refresh);
    QObject::connect(x, &Tables::addProduct,&b, &ProductRegister::addTrigger);
    QObject::connect(x, &Tables::addService,&s, &serviceEdit::regOn);
    QObject::connect(x, &Tables::editService,&s, &serviceEdit::trigger);
    QObject::connect(x, &Tables::addCustomer,&c, &CustomerForm::regOn);
    QObject::connect(x, &Tables::editCustomer,&c, &CustomerForm::trigger);
    QObject::connect(x, &Tables::addDevice, &d ,&DeviceForm::trigger);
    QObject::connect(x, &Tables::editDevice, &d ,&DeviceForm::editDevice);
    QObject::connect(&d, &DeviceForm::optionPage,&a, &AddOption::setupOption);
    QObject::connect(&d, &DeviceForm::itemPage,&a, &AddOption::setupItem);
    QObject::connect(&d, &DeviceForm::devicePage,&a, &AddOption::setupDevice);
    QObject::connect(&d, &DeviceForm::belongingPage,&a,&AddOption::setupBelonging);
    QObject::connect(&a, &AddOption::updatePage,&d , &DeviceForm::refresh);
    QObject::connect(&d, &DeviceForm::addCustomer,&c, &CustomerForm::regOn);
    QObject::connect(&a, &AddOption::addAbr,&aa, &AddAbr::setup);
//    MyFunctions* myFunctions = new MyFunctions(this);  // Create MyFunctions object
//    QObject::connect(myFunctions, &MyFunctions::dataReady, this, &MainWindow::onDataReady);
    setBtnIcon();
//    d.show();
//    x.show();
}

//QLabel lblImage;

//lblImage->setPixmap( QPixmap( "big_image.jpg" ) );

//lblImage->setScaledContents( true );

//lblImage->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

void MainWindow::onDataReady() {
    // qDebug() << "Data is ready, now we can safely use deviceFromSN()";
}

void MainWindow::setBtnIcon(){


    ui->productBtn->setIcon(QIcon("C:/Users/kiafa/Documents/QtDBS/images/products.png"));
    ui->deviceBtn->setIcon(QIcon("C:/Users/kiafa/Documents/QtDBS/images/Hardware.png"));
    ui->customerBtn->setIcon(QIcon("C:/Users/kiafa/Documents/QtDBS/images/customers.png"));
    ui->serviceBtn->setIcon(QIcon("C:/Users/kiafa/Documents/QtDBS/images/services.png"));



    ui->productBtn->setIconSize(ui->productBtn->size());
    ui->deviceBtn->setIconSize(ui->deviceBtn->size());
    ui->customerBtn->setIconSize(ui->customerBtn->size());
    ui->serviceBtn->setIconSize(ui->serviceBtn->size());

}
void MainWindow::setupTable(QString a){
    emit setupTables(a);
}
MainWindow::~MainWindow()
{
//    MyFunctions::initializeData();
    delete ui;
    delete tables;
}

void MainWindow::on_productBtn_clicked()
{
    x->setupTable("محصولات");
    this->hide();
}


void MainWindow::on_deviceBtn_clicked()
{
    x->setupTable("دستگاه ها");
    this->hide();
}


void MainWindow::on_serviceBtn_clicked()
{
    x->setupTable("خدمات");
    this->hide();
}


void MainWindow::on_customerBtn_clicked()
{
    x->setupTable("مشتریان");
    this->hide();

}

