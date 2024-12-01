#ifndef DEVICEFORM_H
#define DEVICEFORM_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QList>
#include <QPushButton>
#include <QBoxLayout>
#include <QCheckBox>
#include "DatabaseConnection.h"
#include <QSqlQuery>
#include <QProgressBar>

namespace Ui {
class DeviceForm;
}

class DeviceForm : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceForm(QWidget *parent = nullptr);
    ~DeviceForm();
    void setup ();
    void editDevice(QString device, unsigned int id);
    void trigger(QString device);
    void refresh(QString arg1);
    void clearPage();
    void getCustomers();
    void closeEvent(QCloseEvent *event) override;
    void addBulk();
signals:
    void optionPage(QString deviceName,QString itemName);
    void removeOptionPage(QString deviceName,QString itemName);
    void itemPage(QString deviceName);
    void devicePage();
    void addCustomer();
    void belongingPage(QString deviceName);
    void hideBelongingPage(QString deviceName);
    void pageUpdate();
    void addAbr();
    void showPB();
    void hidePB();
    void setPBVal(int val);
    void setPBRange(int range);
    void editItem(QString device);
    void closeEditItem();
    void openQREdit();
private slots:
    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_SubmitBtn_clicked();

    void on_AddItemBtn_clicked();

    // virtual void closeEvent(QCloseEvent *event);

    void on_CustomerCombo_editTextChanged(const QString &arg1);

    void on_pushButton_clicked();

    void populateEdit(QString device, unsigned int id);

    void adminMode();

    void on_pushButton_2_clicked();


    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_3_clicked();

    void on_EditQRBtn_clicked();

private:
    void createBelonging(QString itemName,int index);
    void createNewItem(QString itemName , int index);
    QStringList setupOptions( QString itemName);
    void clearLayout(QLayout *layout);
    void addOption(QString deviceName,QString itemName);
    void removeOption(QString deviceName,QString itemName);
    void addItem(QString deviceName);
    void addDevice();
    void submit(QString SN,int count);
    void addBelonging(QString deviceName);
    void hideBelonging(QString deviceName);
    void keyBinds();
    bool checkBulkSN();
    void setColumns();
    void setChecks();
    void setCombos();
    void handleStarted();
    void handleFinished();
    void loadDate(unsigned int id);
    void loadLastSN();
    bool askForQR();
    QString currentDevice;
    int adder;
    Ui::DeviceForm *ui;
    QList<QLabel*> labels;
    QList<QComboBox*> comboBoxes;
    QList<QPushButton*> addBtns;
    QList<QCheckBox*> checkBoxes;
    DatabaseConnection &db;
    bool edit;
    bool admiMode;
    QStringList customers;
    void keyPressEvent(QKeyEvent *event) override;
    void setTabOrders();
    QStringList columns;
    QString checks;
    QStringList combos;
    bool checked;
    unsigned int max;
    unsigned int id;
    // QProgressBar progressBar;
};

#endif // DEVICEFORM_H
