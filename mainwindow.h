#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//#include<QSqlDatabase>
#include <QMainWindow>
#include "deviceform.h"
#include "tables.h"
#include "productregister.h"
#include "searchform.h"
#include "myfunctions.h"
#include "serviceedit.h"
#include "customerform.h"
#include "itemhandler.h"
#include "jsonhandler.h"
#include "addoption.h"
#include "myfunctions.h"
#include "addabr.h"
#include "deleteoption.h"
#include <edititem.h>
#include <hidebelonging.h>
#include <exporttoexcel.h>
#include <DllHandler.h>
#include "loadqrtext.h"
#include "deleteitem.h"

class Tables;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void onDataReady();
    void setBtnIcon();
    void setupTable(QString a);

private slots:
    void closePages();
    void on_productBtn_clicked();
    void on_deviceBtn_clicked();

    void on_serviceBtn_clicked();

    void on_customerBtn_clicked();

signals:
    void setupTables(QString a);

private:
    Ui::MainWindow *ui;
    Tables *tables;
    DeviceForm d;
    Tables *x = new Tables(this);
    ProductRegister b;
    SearchForm r;
    serviceEdit s;
    CustomerForm c;
    AddOption a;
    AddAbr aa;
    DeleteOption dO;
    DatabaseConnection &db;
    EditItem EI;
    ExportExcel EE;
    HideBelonging hb;
    LoadQRText QR;
    DeleteItem DI;
    void keyPressEvent(QKeyEvent *event) override;

};
#endif // MAINWINDOW_H
