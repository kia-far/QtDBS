#include "changedb.h"
#include "ui_changedb.h"
#include <QKeyEvent>
ChangeDB::ChangeDB(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChangeDB)
{
    ui->setupUi(this);
}

ChangeDB::~ChangeDB()
{
    delete ui;
}
void ChangeDB::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter){
        bool moved = this->focusNextChild();
        if (moved) {
            // qDebug() << "Moved focus to the next widget.";
        }

        // Mark the event as accepted
        event->accept();
    }
    else{}
}
