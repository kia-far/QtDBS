#include "searchform.h"
#include "ui_searchform.h"
#include "QDebug"
#include <QDialogButtonBox>
#include <QPushButton>
#include <QKeyEvent>
#include "itemhandler.h"

SearchForm::SearchForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchForm)
{
    ui->setupUi(this);
    QPushButton *okbtn = ui->buttonBox->button(QDialogButtonBox::Ok);
    okbtn->setText("جستجو");
    QPushButton *rejbtn = ui->buttonBox->button(QDialogButtonBox::Cancel);
    rejbtn->setText("بستن");
    showItemSearch(false);
    showBelongingSearch(false);
}

SearchForm::~SearchForm()
{
    delete ui;
}
int currentSearch;

void SearchForm::receiveTableIndex(int current,QString device){
    // qDebug() << device;
    currentDev=device;
    currentSearch = current;
    createCombo();
        this->show();
    this->activateWindow();

};
void SearchForm::refresh(int current){
    currentSearch = current;
    if (currentSearch==0){emit searchWorking("ID","");}
    else if(currentSearch==1){emit searchWorking("ID","");}
    else if(currentSearch==2){emit searchWorking("SerialNumber","");}
    else{emit searchWorking("ProductInfo.SerialNO","");}
};

void SearchForm::createCombo(){
    ui->comboBox->blockSignals(true);
    showItemSearch(false);
    showBelongingSearch(false);
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
        ui->comboBox->addItem("قطعات");

    } else{
        ui->comboBox->addItem("شماره سریال");
        ui->comboBox->addItem("نام محصول");
        ui->comboBox->addItem("شماره anydesk");
    }
    ui->comboBox->blockSignals(false);

}

void SearchForm::on_buttonBox_accepted()
{
    QString searchText;
    if (!(ui->comboBox->currentText()=="متعلقات"))
    {searchText = ui->lineEdit->text();}

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
        else if (ui->comboBox->currentText()=="متعلقات"){emit searchWorking("belongings",ui->comboBox_4->currentText());}
        else if (ui->comboBox->currentText()=="قطعات"){
            if(ui->comboBox_3->count() >0){ emit searchWorking(ui->comboBox_2->currentText(),ui->comboBox_3->currentText());}
            else{this->close();}
        }
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
    if(arg1=="متعلقات"){showItemSearch(false);showBelongingSearch(true);}
    else if(arg1=="قطعات"){
        showBelongingSearch(false);
        showItemSearch(true);
    }
    else {showItemSearch(false);showBelongingSearch(false);}

}


void SearchForm::on_lineEdit_returnPressed()
{
    on_buttonBox_accepted();
}

void SearchForm::keyPressEvent(QKeyEvent *event){
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

void SearchForm::showItemSearch(bool istrue){
    qDebug() << "entered";
    if(!istrue)ui->widget->hide();
    else {
        ui->widget->show();
        if(!currentDev.isEmpty()){
            QStringList Items = ItemHandler::loadItems(currentDev);
            if(!Items.isEmpty()){
            ui->comboBox_2->blockSignals(true);
            ui->comboBox_2->clear();
            ui->comboBox_2->addItems(Items);
            ui->comboBox_2->blockSignals(false);
            populateOptions(ui->comboBox_2->currentText());
            }}
    }
    qDebug() << "exited ";
}
void SearchForm::populateOptions(QString item){
    QStringList options = ItemHandler::loadOptions(currentDev,item);
    if(options.size()>0){
    ui->comboBox_3->clear();
    ui->comboBox_3->addItem("هیچ کدام");
    ui->comboBox_3->addItems(options);}

}
void SearchForm::showBelongingSearch(bool istrue){
    if(!istrue){ui->comboBox_4->hide();ui->lineEdit->show();}
    else{
        ui->lineEdit->hide();
        QStringList belongings = ItemHandler::loadbelongings(currentDev);
        ui->comboBox_4->clear();
        ui->comboBox_4->addItems(belongings);
        ui->comboBox_4->show();
    }
}

void SearchForm::on_comboBox_2_currentIndexChanged(int index)
{
    QString item = ui->comboBox_2->currentText();
    populateOptions(item);
}



