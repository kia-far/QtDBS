#include "searchform.h"
#include "ui_searchform.h"
#include "QDebug"
#include <QDialogButtonBox>
#include <QPushButton>

SearchForm::SearchForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchForm)
{
    ui->setupUi(this);
    QPushButton *okbtn = ui->buttonBox->button(QDialogButtonBox::Ok);
    okbtn->setText("جستجو");
    QPushButton *rejbtn = ui->buttonBox->button(QDialogButtonBox::Cancel);
    rejbtn->setText("بستن");
}

SearchForm::~SearchForm()
{
    delete ui;
}
int currentSearch;

void SearchForm::receiveTableIndex(int current){
    currentSearch = current;
    createCombo();
    this->show();
};
void SearchForm::refresh(int current){
    currentSearch = current;
    if (currentSearch==0){emit searchWorking("ID","");}
    else if(currentSearch==1){emit searchWorking("ID","");}
    else if(currentSearch==2){emit searchWorking("SerialNumber","");}
    else{emit searchWorking("ProductInfo.SerialNO","");}
};

void SearchForm::createCombo(){
    ui->comboBox->clear(); // Clear existing items

    if (currentSearch == 0) {
        ui->comboBox->addItem("نام");
        // ui->comboBox->addItem("Product");
        ui->comboBox->addItem("شناسه");
    } else if (currentSearch == 1) {
        ui->comboBox->addItem("محصول");
        ui->comboBox->addItem("مشتری");
        ui->comboBox->addItem("تاریخ");
        ui->comboBox->addItem("مسئول");
        ui->comboBox->addItem("نوع خدمات");
        ui->comboBox->addItem("قطعه خراب");
        ui->comboBox->addItem("توضیحات");
    } else if(currentSearch == 2) {
        ui->comboBox->addItem("شماره سریال");
        ui->comboBox->addItem("نام مشتری");
        ui->comboBox->addItem("متعلقات");

    } else{
        ui->comboBox->addItem("شماره سریال");
        ui->comboBox->addItem("نام محصول");
        ui->comboBox->addItem("شماره anydesk");
    }
}

void SearchForm::on_buttonBox_accepted()
{
    QString searchText = ui->lineEdit->text();
//    qDebug() << "accepted";
    if (currentSearch == 0){/*Customers*/
        if (ui->comboBox->currentText()=="نام"){emit searchWorking("Name",searchText);}
        // else if (ui->comboBox->currentText()=="Product"){emit searchWorking("Product",searchText);}
        else if (ui->comboBox->currentText()=="شناسه"){emit searchWorking("ID",searchText);}
        else{}
    }
    else if (currentSearch == 1){/*Services

        ui->comboBox->addItem("محصول");
        ui->comboBox->addItem("مشتری");
        ui->comboBox->addItem("تاریخ");
        ui->comboBox->addItem("مسئول");
        ui->comboBox->addItem("نوع خدمات");
        ui->comboBox->addItem("قطعه خراب");
        ui->comboBox->addItem("توضیحات");*/
        if (ui->comboBox->currentText()=="محصول"){emit searchWorking("Product",searchText);}
        else if (ui->comboBox->currentText()=="مشتری"){emit searchWorking("Customer",searchText);}
        else if (ui->comboBox->currentText()=="تاریخ"){emit searchWorking("Date",searchText);}
        else if (ui->comboBox->currentText()=="مسئول"){emit searchWorking("Authority",searchText);}
        else if (ui->comboBox->currentText()=="نوع خدمات"){emit searchWorking("ServiceType",searchText);}        else if (ui->comboBox->currentText()=="Description"){emit searchWorking("Description",searchText);}
        else if (ui->comboBox->currentText()=="قطعه خراب"){emit searchWorking("ImpairedPart",searchText);}
        else if (ui->comboBox->currentText()=="توضیحات"){emit searchWorking("Description",searchText);}
        else {}
    }
    else if (currentSearch == 2){/*Devices*/
        if (ui->comboBox->currentText()=="شماره سریال"){emit searchWorking("SerialNumber",searchText);}
        else if (ui->comboBox->currentText()=="نام مشتری"){emit searchWorking("CustomerName",searchText);}
        else if (ui->comboBox->currentText()=="متعلقات"){emit searchWorking("belongings",searchText);}
        else {}
    }
    else {/*Product*/
        if (ui->comboBox->currentText()=="شماره سریال"){emit searchWorking("ProductInfo.SerialNO",searchText);}
        else if (ui->comboBox->currentText()=="نام محصول"){emit searchWorking("ProductInfo.ProductName",searchText);}
        else if (ui->comboBox->currentText()=="شماره anydesk"){emit searchWorking("ProductInfo.AnyDeskNO",searchText);}
        else {}
    }
    ui->lineEdit->setText("");
    this->close();
}



void SearchForm::on_buttonBox_rejected()
{
    this->close();
}


void SearchForm::on_comboBox_currentIndexChanged(const QString &arg1)
{
//    qDebug() << arg1 + "hello";
}


void SearchForm::on_lineEdit_returnPressed()
{
    on_buttonBox_accepted();
}

