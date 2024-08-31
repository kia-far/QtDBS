#include "searchform.h"
#include "ui_searchform.h"
#include "QDebug"

SearchForm::SearchForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchForm)
{
    ui->setupUi(this);
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
    else if(currentSearch==2){emit searchWorking("SerialNum","");}
    else{emit searchWorking("ProductInfo.SerialNO","");}
};

void SearchForm::createCombo(){
    ui->comboBox->clear(); // Clear existing items

    if (currentSearch == 0) {
        ui->comboBox->addItem("Name");
        ui->comboBox->addItem("Product");
        ui->comboBox->addItem("ID");
    } else if (currentSearch == 1) {
        ui->comboBox->addItem("Date");
        ui->comboBox->addItem("Description");
        ui->comboBox->addItem("ID");
    } else if(currentSearch == 2) {
        ui->comboBox->addItem("Serial Number");
        ui->comboBox->addItem("Customer name");
        ui->comboBox->addItem("Belongings");

    } else{
        ui->comboBox->addItem("Serial Number");
        ui->comboBox->addItem("Product Name");
        ui->comboBox->addItem("Anydesk Number");
    }
}

void SearchForm::on_buttonBox_accepted()
{
    QString searchText = ui->lineEdit->text();
//    qDebug() << "accepted";
    if (currentSearch == 0){/*Customers*/
        if (ui->comboBox->currentText()=="Name"){emit searchWorking("Name",searchText);}
        else if (ui->comboBox->currentText()=="Product"){emit searchWorking("Product",searchText);}
        else if (ui->comboBox->currentText()=="ID"){emit searchWorking("ID",searchText);}
        else{}
    }
    else if (currentSearch == 1){/*Services*/
        if (ui->comboBox->currentText()=="Date"){emit searchWorking("Date",searchText);}
        else if (ui->comboBox->currentText()=="Description"){emit searchWorking("Description",searchText);}
        else if (ui->comboBox->currentText()=="ID"){emit searchWorking("ID",searchText);}
        else {}
    }
    else if (currentSearch == 2){/*Devices*/
        if (ui->comboBox->currentText()=="Serial Number"){emit searchWorking("SerialNum",searchText);}
        else if (ui->comboBox->currentText()=="Customer name"){emit searchWorking("Customer name",searchText);}
        else if (ui->comboBox->currentText()=="Belongings"){emit searchWorking("Belongings",searchText);}
        else {}
    }
    else {/*Product*/
        if (ui->comboBox->currentText()=="Serial Number"){emit searchWorking("ProductInfo.SerialNO",searchText);}
        else if (ui->comboBox->currentText()=="Product Name"){emit searchWorking("ProductInfo.ProductName",searchText);}
        else if (ui->comboBox->currentText()=="Anydesk Number"){emit searchWorking("ProductInfo.AnyDeskNO",searchText);}
        else {}
    }
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

