#include "deviceedit.h"
#include "ui_deviceedit.h"
#include "myfunctions.h"
#include <QtDebug>
#include <QSqlQuery>
#include <QSqlError>

int currentEdit;

DeviceEdit::DeviceEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceEdit)
{
    ui->setupUi(this);
    dbd = QSqlDatabase::addDatabase("QSQLITE");
    dbd.setDatabaseName("C:\\Users\\kiafa\\Desktop\\Job\\DB\\sqlitestudio_x64-3.4.4\\SQLiteStudio\\InfoDB");
    dbd.open();
}

DeviceEdit::~DeviceEdit()
{
    delete ui;
}
