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
    void editDevice(QString device, int id);
    void trigger(QString device);
    void refresh();
    void clearPage();

signals:
    void optionPage(QString deviceName,QString itemName);
    void itemPage(QString deviceName);
    void devicePage();
    void addCustomer();
    void belongingPage(QString deviceName);
private slots:
    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_SubmitBtn_clicked();

    void on_AddItemBtn_clicked();

    void on_addDeviceBtn_clicked();

    void on_CustomerCombo_editTextChanged(const QString &arg1);

    void on_pushButton_clicked();

    void populateEdit(QString device, int id);

    void on_AddDevBtn_clicked();

    void adminMode();

//    void on_AddOptBtn_clicked();

//    void on_AddBelBtn_clicked();

private:
    void createBelonging(QString itemName,int index);
    void createNewItem(QString itemName , int index);
    QStringList setupOptions( QString itemName);
    void clearLayout(QLayout *layout);
    void addOption(QString deviceName,QString itemName);
    void addItem(QString deviceName);
    void addDevice();
    void submit();
    void addBelonging(QString deviceName);
    void keyBinds();
    QString currentDevice;
    int adder;
    Ui::DeviceForm *ui;
    QList<QLabel*> labels;
    QList<QComboBox*> comboBoxes;
    QList<QPushButton*> addBtns;
    QList<QCheckBox*> checkBoxes;
    QStringList getCustomers(QString something);
    DatabaseConnection &db;
    bool edit;
    bool admiMode;
};

#endif // DEVICEFORM_H
