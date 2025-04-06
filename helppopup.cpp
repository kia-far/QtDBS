#include "helppopup.h"
#include "ui_helppopup.h"

helpPopUp::helpPopUp(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::helpPopUp)
{
    ui->setupUi(this);
}

helpPopUp::~helpPopUp()
{
    delete ui;
}

void helpPopUp::setHelp(QString text){
    ui->textEdit->setText(text);
    this->show();
}

void helpPopUp::on_pushButton_clicked()
{
    this->close();
}

