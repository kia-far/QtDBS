#ifndef TABLES_H
#define TABLES_H

#include <QWidget>
#include "proxyview.h"
#include "MyTableProxy.h"
#include "productproxy.h"
#include <DatabaseConnection.h>
#include <QLabel>
#include <QLineEdit>
#include <QList>
#include <QCheckBox>

namespace Ui {
class Tables;
}
class MainWindow;
class Tables : public QWidget
{
    Q_OBJECT

public:
    explicit Tables(MainWindow *mainWin,QWidget *parent = nullptr);
    ~Tables();
    void searchInfo(QString searchParam,QString searchText);
    void setupTable(QString table);
    void pageRefresh();
    void handlePBStarted();
    void handlePBFinished();
    void setPBRange(int a);
    void setPBValue(int a);
    void handleBtnEnable(bool a);
    void emptyWidget();
signals:
    void editDevice(QString device,unsigned int id);
    void edit(unsigned int serialNum,int index);
    void searchActive(int current);
    void editProduct(unsigned int serialNum);
    void refreshActive(int current);
    void addProduct();
    void addDevice(QString device);
    void addService();
    void editService(unsigned int serialNum);
    void addCustomer();
    void editCustomer(unsigned int serialNum);

private slots:
    void getExport();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_EditBtn_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_SearchBtn_clicked();

    void on_AddBtn_clicked();

    void on_RefreshBtn_clicked();

    void on_mainWindowBtn_clicked();


    void on_comboBox_2_currentIndexChanged(const QString &arg1);

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_deleteBtn_clicked();


    void on_toolButton_clicked();

private:
    void deleteRow(unsigned int ID, QString device);
    void hideColumns();
    void showColumns();
    void populateLabel(int row);
    void setupWidget();
    void clearLayout(QLayout *layout);
    Ui::Tables *ui;
    void keybinds();
    ProxyView *View;
    MyTableProxy *Customer;
    MyTableProxy *Services;
    ProductProxy *Product;
    DatabaseConnection &db;
    MainWindow *mainwindow;
    QString currentDevice;
    QList<QLabel*>labels;
    QList<QLineEdit*>lineEdits;
    QList<QCheckBox*>checkBoxes;
    void keyPressEvent(QKeyEvent *event) override;
    bool batchInProgress;
    int selectedRow;
};

#endif // TABLES_H
