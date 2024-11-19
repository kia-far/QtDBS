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

    QAction *f0 = new QAction(this);
    f0->setShortcut(Qt::Key_P | Qt::CTRL);

    connect(f0, SIGNAL(triggered()), this, SLOT(testQrCode()));
    this->addAction(f0);
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

int MainWindow::testQrCode(){
    if (!DllHandler::loadDll("WINPSK")) {  // No need to include .dll
        qDebug() << "hi";
        return -1;
    }

    qDebug() << DllHandler::closePort();
    qDebug() << DllHandler::openPort(1);
    qDebug() << DllHandler::clearbuffer();
    qDebug() << DllHandler::setDirection('B');
    unsigned int i = 1;
    qDebug() << DllHandler::setPrintSpeed(i);
    // qDebug() <<DllHandler::setLabelHeight(160, 1);
    qDebug() <<DllHandler::setLabelWidth(420);
    qDebug() << DllHandler::setFont(160,110,0,4,1,1,'N',"N98A0001");

    QString p1 = "PACTOS Inc.";
    QString p2 = "\n";
    QString p3 = QString::fromUtf8( "شرکت پکتوس");
    QString p4 = "\n";
    QString p5 = QString::fromUtf8( "برجسته نگار هوشمند همراه");
    QString p6 = "\n";
    QString p7 = QString::fromUtf8("نام خریدار: نهاد کتابخانه های عمومی استان یزد");
    QString p8 = "\n";
    QString p9 = QString::fromUtf8( "شماره سریال");
    QString p10 = "\n";
    QString p11 =  ": N98A0001";
    QString p12 = "\n";
    QString p13 = QString::fromUtf8( "تاریخ خرید");
    QString p14 = "\n";
    QString p15 = "1398/11/17";
    QString p16 = "\n";
    QString p17 = QString::fromUtf8( "مدت گارانتی: یکسال");
    QString p18 = "\n";
    QString p19 = "www.pactos.ir";
    QString p20 = "\n";
    QString p21 = "Email: info@pactos.ir";
    qDebug() <<DllHandler::drawQRCode(20, 25, p1+p2+p3+p4+p5+p6+p7+p8+p9+p10+p11+p12+p13+p14+p15+p16+p17+p18+p19+p20+p21);
    qDebug() << DllHandler::drawBarCode(160,40, "N98A0001");
    qDebug() <<DllHandler::printLabel(1, 1)<<"print";

    qDebug() <<DllHandler::closePort()<<"closeport";
    DllHandler::unloadDll();

    return 0;
}
