#include "edititem.h"
#include "ui_edititem.h"
#include <myfunctions.h>
#include <itemhandler.h>
#include <QMessageBox>

EditItem::EditItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EditItem)
{
    ui->setupUi(this);
}

EditItem::~EditItem()
{
    delete ui;
}

void EditItem::setup(QString device){
    ui->label->setText("ویرایش قطعه "+ device);
    this->device = device;
    ui->listWidget->clear();
    ui->listWidget->addItems(ItemHandler::loadItems(device));
    this->show();
    this->activateWindow();
}



void EditItem::on_pushButton_clicked()
{
    if(ui->lineEdit->text().isEmpty()){
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("Error");
        msgBox.setText("نام قطعه نمیتواند خالی باشد");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }
    else{
    qDebug () << "device is :" << device;
    QString newText = "";
    QString text = ui->lineEdit->text();
    for(int i=0;i<text.size(); i++){
        if (text.at(i)==" "){newText.append("_");}
        else{newText.append(text.at(i));}}
    ItemHandler::editItem(device,item,newText);
    emit updateForms(device);
    emit refreshTable();
    this->close();}
}


void EditItem::on_listWidget_itemClicked(QListWidgetItem *item)
{
    this->item=item->text();
    ui->lineEdit->setText(item->text());

}

void EditItem::closeForm(){
    this->close();
}
