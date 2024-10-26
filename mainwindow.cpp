#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIcon>
#include <QDebug>
#include <QSqlQuery>
#include <QApplication>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , tables(new Tables(this))
    , db(DatabaseConnection::getInstance())
{
    ui->setupUi(this);
    // qDebug() << qApp->applicationDirPath();
    // qDebug() << ItemHandler::loadDevices();
    // qDebug() << "reverseSN" << MyFunctions::reverseSN("B00n8892");
    this->show();
    this->activateWindow();

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
    QObject::connect(&d, &DeviceForm::removeOptionPage,&dO,&DeleteOption::Setup);
    QObject::connect(&d, &DeviceForm::itemPage,&a, &AddOption::setupItem);
    QObject::connect(&d, &DeviceForm::devicePage,&a, &AddOption::setupDevice);
    QObject::connect(&b, &ProductRegister::devicePage,&a, &AddOption::setupDevice);
    QObject::connect(&d, &DeviceForm::belongingPage,&a,&AddOption::setupBelonging);
    QObject::connect(&a, &AddOption::updatePage,&d , &DeviceForm::refresh);
    QObject::connect(&d, &DeviceForm::addCustomer,&c, &CustomerForm::regOn);
    QObject::connect(&d, &DeviceForm::addAbr,&aa, &AddAbr::setup);
    QObject::connect(&b, &ProductRegister::addAbr,&aa, &AddAbr::setup);
    QObject::connect(&d, &DeviceForm::pageUpdate, x,&Tables::pageRefresh);
    QObject::connect(&b, &ProductRegister::pageUpdate, x,&Tables::pageRefresh);
    QObject::connect(&c, &CustomerForm::callPageRefresh, x,&Tables::pageRefresh);
    QObject::connect(&c, &CustomerForm::callPageRefresh, &d, &DeviceForm::getCustomers);
    QObject::connect(&s, &serviceEdit::callPageRefresh, x,&Tables::pageRefresh);
    QObject::connect(&dO,&DeleteOption::refresh,&d,&DeviceForm::refresh);
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

    QString addr = qApp->applicationDirPath();
    ui->productBtn->setIcon(QIcon(addr+"/images/products.png"));
    ui->deviceBtn->setIcon(QIcon(addr+"/images/Hardware.png"));
    ui->customerBtn->setIcon(QIcon(addr+"/images/customers.png"));
    ui->serviceBtn->setIcon(QIcon(addr+"/images/services.png"));



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

void MainWindow::keyPressEvent(QKeyEvent *event){
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
