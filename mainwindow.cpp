#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIcon>
#include <QDebug>
#include <QSqlQuery>
#include <QApplication>
#include <QKeyEvent>
#include <iostream>

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
    this->showMaximized();
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
    QObject::connect(&d, &DeviceForm::hideBelongingPage,&hb, &HideBelonging::setup);
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
    QObject::connect(&d, &DeviceForm::showPB, this,&MainWindow::closePages);
    QObject::connect(&d, &DeviceForm::hidePB, x,&Tables::handlePBFinished);
    QObject::connect(&d, &DeviceForm::setPBRange, x,&Tables::setPBRange);
    QObject::connect(&d, &DeviceForm::setPBVal, x,&Tables::setPBValue);
    QObject::connect(&d, &DeviceForm::editItem, &EI, &EditItem::setup);
    QObject::connect(&EI,&EditItem::updateForms,&d, &DeviceForm::refresh);
    QObject::connect(&EI,&EditItem::refreshTable,x,&Tables::pageRefresh);
    QObject::connect(&d, &DeviceForm::closeEditItem,&EI, &EditItem::closeForm);
    QObject::connect(&d, &DeviceForm::closeEditItem,&hb,&HideBelonging::closePage);
    QObject::connect(&hb, &HideBelonging::refreshDevPage,&d,&DeviceForm::refresh);
    QObject::connect(&EE,&ExportExcel::loadEmpty,x,&Tables::emptyWidget);
    QObject::connect(&d, &DeviceForm::openQREdit, &QR,&LoadQRText::setup);
    QObject::connect(&d, &DeviceForm::openDeleteItem,&DI,&DeleteItem::setup);
    QObject::connect(&a, &AddOption::refreshDevices,&d, &DeviceForm::refresh);
    QObject::connect(&DI, &DeleteItem::refreshDevices,&d,&DeviceForm::refresh);
    QObject::connect(&DI, &DeleteItem::refreshTable,x,&Tables::pageRefresh);
//    MyFunctions* myFunctions = new MyFunctions(this);  // Create MyFunctions object
//    QObject::connect(myFunctions, &MyFunctions::dataReady, this, &MainWindow::onDataReady);
    setBtnIcon();
//    d.show();
//    x.show();
}

void MainWindow::closePages(){
    x->handlePBStarted();
    r.close();
    aa.close();
    a.close();
    s.close();
    b.close();
    c.close();
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


