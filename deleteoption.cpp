#include "deleteoption.h"
#include "ui_deleteoption.h"
#include <myfunctions.h>
#include <itemhandler.h>

DeleteOption::DeleteOption(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DeleteOption)
{
    ui->setupUi(this);
}

DeleteOption::~DeleteOption()
{
    delete ui;
}

QStringList DeleteOption::setupOptions(QString device,QString item){
    return ItemHandler::loadOptions(device,item);
}

void DeleteOption::Setup(QString device,QString item){
    this->show();
    this->device = device;
    this->item = item;
    ui->comboBox->clear();
    ui->comboBox->addItem("هیچ کدام");
    ui->comboBox->addItems(setupOptions(device, item));
    ui->comboBox->setCurrentIndex(0);
}
void DeleteOption::Submit(QString device,QString item){
    ItemHandler::removeOptions(device,item,ui->comboBox->currentText());
    emit refresh(device);
    this->close();
}

void DeleteOption::on_pushButton_clicked()
{
    Submit(device,item);
}

