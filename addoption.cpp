#include "addoption.h"
#include "ui_addoption.h"
#include "itemhandler.h"
#include <QDebug>
AddOption::AddOption(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddOption),
    lineEdit_2(new QLineEdit()),
    devCalled(false)
{
    ui->setupUi(this);
//    devCalled=false;
    ui->verticalLayout->addWidget(lineEdit_2,1);
    lineEdit_2->hide();
}

AddOption::~AddOption()
{
    delete ui;
}

void AddOption::setupDevice(){
    func = "device";
    this->setWindowTitle("Add Device");
    ui->label->setText("New Device");
    if(lineEdit_2->isHidden()){lineEdit_2->show();}
    lineEdit_2->setText("");
    this->show();
    devCalled =true;
}
void AddOption::setupItem(QString deviceName){
    cleanupDevice();
    device = deviceName;
    func = "item";
    this->setWindowTitle("Add Item");
    ui->label->setText("New Item");
    this->show();
}
void AddOption::setupOption(QString deviceName,QString itemName){
    cleanupDevice();
    device = deviceName;
    item = itemName;
    func = "option";
    this->setWindowTitle("Add Option");
    ui->label->setText("New Option");
    this->show();
}
void AddOption::on_pushButton_clicked()
{
    QString newText = "";
    if (func == "device"){
        QString text = ui->lineEdit->text();
        for(int i=0;i<text.size(); i++){
            if (text.at(i)==" "){newText.append("_");}
            else{newText.append(text.at(i));}
        }
        ItemHandler::addDevices(text,lineEdit_2->text());
    }
    else if (func == "item"){
        QString text = ui->lineEdit->text();
        for(int i=0;i<text.size(); i++){
            if (text.at(i)==" "){newText.append("_");}
            else{newText.append(text.at(i));}
        }
        ItemHandler::addItems(device , newText);
    }
    else if (func == "option"){
    QString option = ui->lineEdit->text();
    qDebug() << "these are gonna go out " <<device << item << option;
    ItemHandler::addOptions(device,item,option);
    }
    else;
//    ItemHandler::addBelonging(device,ui->lineEdit->text());
    emit updatePage();
    this->close();
}
void AddOption::cleanupDevice() {
    if (devCalled) {
        lineEdit_2->hide();
    }
    devCalled =false;
}
