#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//#include<QSqlDatabase>
#include <QMainWindow>
#include "deviceform.h"
#include "tables.h"
//#include "requestform.h"
#include "deviceedit.h"
#include "edittable.h"
#include "productregister.h"
#include "searchform.h"
#include "myfunctions.h"
#include "serviceedit.h"
#include "customerform.h"
#include "itemhandler.h"
#include "jsonhandler.h"
#include "addoption.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setBtnIcon();

private slots:
    void on_productBtn_clicked();

private:
    Ui::MainWindow *ui;
    DeviceForm d;
    EditTable e;
    DeviceEdit m;
    Tables x;
//    RequestForm z;
    ProductRegister b;
    SearchForm r;
    serviceEdit s;
    CustomerForm c;
    AddOption a;
//    QSqlDatabase db;
};
#endif // MAINWINDOW_H
