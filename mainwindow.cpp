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
    QObject::connect(&d, &DeviceForm::optionPage,&a, &AddOption::setupOption);
    QObject::connect(&d, &DeviceForm::itemPage,&a, &AddOption::setupItem);
    QObject::connect(&d, &DeviceForm::devicePage,&a, &AddOption::setupDevice);
    QObject::connect(&a, &AddOption::updatePage,&d , &DeviceForm::refresh);
    QObject::connect(&d, &DeviceForm::addCustomer,&c, &CustomerForm::regOn);

    setBtnIcon();
    d.show();
//    x.show();
}

//QLabel lblImage;

//lblImage->setPixmap( QPixmap( "big_image.jpg" ) );

//lblImage->setScaledContents( true );

//lblImage->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

void MainWindow::setBtnIcon(){

    ui->productBtn->setIconSize(ui->productBtn->size());
    qDebug() <<"size : " <<ui->customerBtn->iconSize();

}
void MainWindow::setupTable(QString a){
    emit setupTables(a);
}
MainWindow::~MainWindow()
{
    delete ui;
    delete tables;
}

void MainWindow::on_productBtn_clicked()
{
    x->setupTable("product");
    this->hide();
}


void MainWindow::on_deviceBtn_clicked()
{
    x->setupTable("device");
    this->hide();
}


void MainWindow::on_serviceBtn_clicked()
{
    x->setupTable("service");
    this->hide();
}


void MainWindow::on_customerBtn_clicked()
{
    x->setupTable("customer");
    this->hide();

}

