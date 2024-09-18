#include "addoption.h"
#include "ui_addoption.h"
#include "itemhandler.h"
#include <QDebug>
#include <QMessageBox>

AddOption::AddOption(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddOption),
    lineEdit_2(new QLineEdit()),
    devCalled(false)
{
    ui->setupUi(this);
//    devCalled=false;
    ui->verticalLayout_3->addWidget(lineEdit_2);
    lineEdit_2->hide();
}

AddOption::~AddOption()
{
    delete ui;
}

void AddOption::setupBelonging(QString deviceName){
    cleanupDevice();
    device = deviceName;
    func = "belonging";
    this->setWindowTitle("افزودن متعلقات");
    ui->label->setText("افزودن متعلقات");
    this->show();
}

void AddOption::showError(QString errorMessage) {
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Critical);  // Set error icon
    msgBox.setWindowTitle("Error");         // Set title
    msgBox.setText(errorMessage);           // Set error message
    msgBox.setStandardButtons(QMessageBox::Ok);  // Add an OK button
    msgBox.exec();  // Show the message box
}

void AddOption::setupDevice() {
    func = "device";
    this->setWindowTitle("افزودن دستگاه");
    ui->label->setText("افزودن دستگاه");

    if (lineEdit_2->isHidden()) {
        lineEdit_2->show();
    }


    lineEdit_2->setText("");
    ui->lineEdit->setPlaceholderText("نام دستگاه");
    lineEdit_2->setPlaceholderText("مخفف نام دستگاه");

    // Create button only if it doesn't exist
    if (!editButton) {
        editButton = new QPushButton;
        editButton->setText("افزودن حرف به دستگاه موجود");
        connect(editButton, &QPushButton::clicked, this, [this]() { emit addAbr(); });
        ui->verticalLayout->addWidget(editButton);
    }

    if (editButton->isHidden()) {
        editButton->show();
    }
    this->show();
    devCalled = true;
}

void AddOption::setupItem(QString deviceName){
    cleanupDevice();
    device = deviceName;
    func = "item";
    this->setWindowTitle("افزودن قطعه");
    ui->label->setText("افزودن قطعه");
    this->show();
}
void AddOption::setupOption(QString deviceName,QString itemName){
    cleanupDevice();
    device = deviceName;
    item = itemName;
    func = "option";
    this->setWindowTitle("افزودن گزینه");
    ui->label->setText("افزودن گزینه");
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
        if(text.isEmpty()||lineEdit_2->text().isEmpty()){
            showError("هر دو خانه را پر کنید");
        }
        else{
            ItemHandler::addDevices(text,lineEdit_2->text().toUpper());}
    }
    else if (func == "belonging"){

        QString text = ui->lineEdit->text();
        if(text.isEmpty()){showError("خانه را پر کنید");}
        else{
            ItemHandler::addBelonging(device,text);}
    }
    else if (func == "item"){
        QString text = ui->lineEdit->text();
        if(text.isEmpty()){showError("خانه را پر کنید");}
        else{
        for(int i=0;i<text.size(); i++){
            if (text.at(i)==" "){newText.append("_");}
            else{newText.append(text.at(i));}
        }
        ItemHandler::addItems(device , newText);
        }}
    else if (func == "option"){
    QString option = ui->lineEdit->text();
        if(option.isEmpty()){showError("خانه را پر کنید");}
        else{
//    qDebug() << "these are gonna go out " <<device << item << option;
    ItemHandler::addOptions(device,item,option);
        }}
    else;
//    ItemHandler::addBelonging(device,ui->lineEdit->text());
    emit updatePage();
    this->close();
}
void AddOption::cleanupDevice() {
    if (devCalled) {
        lineEdit_2->hide();
        editButton->setHidden(true);
    }
    devCalled =false;
}

void AddOption::on_AddOption_destroyed()
{
}

