#include "changedb.h"
#include "ui_changedb.h"

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
