#include "addabr.h"
#include "ui_addabr.h"
#include "itemhandler.h"
#include <QMessageBox>
#include <QKeyEvent>

AddAbr::AddAbr(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddAbr)
{
    ui->setupUi(this);
    // ui->comboBox->addItems(ItemHandler::loadDevices());
    // ui->comboBox->setCurrentIndex(0);
}

AddAbr::~AddAbr()
{
    delete ui;
}

void AddAbr::setup() {
        this->show();
    this->activateWindow();

    ui->comboBox->clear();
    ui->comboBox->addItems(ItemHandler::loadDevices());
    ui->comboBox->setCurrentIndex(0);
}
void AddAbr::on_submitButton_clicked()
{
    if(ui->lineEdit->text().length()!=1){
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("Error");
        msgBox.setText("مخفف باید یک حرف باشد");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }
    else{
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Error");
        msgBox.setText("آیا میخواهید حرف جدیدی را به شماره سریال دستگاه انتخاب شده اضافه کنید؟");
        msgBox.setStandardButtons(QMessageBox::Yes| QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        int res = msgBox.exec();
        switch(res) {
        case QMessageBox::Yes :{
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Warning);
            msgBox.setWindowTitle("Error");
            msgBox.setText("این تغییر برگشت پذیر نیست آیا مطمئنید؟");
            msgBox.setStandardButtons(QMessageBox::Yes| QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::No);
            int res = msgBox.exec();
            switch(res) {
            case QMessageBox::Yes :{
                ItemHandler::addAbr(ui->comboBox->currentText(),ui->lineEdit->text().at(0));
                this->close();
                break;
            }
            case QMessageBox::No :{
                break;
            }
            default :
                break;

            }            break;
        }
        case QMessageBox::No :{
            break;
        }
        default :
            break;

        }
    }
}

void AddAbr::keyPressEvent(QKeyEvent *event){
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
