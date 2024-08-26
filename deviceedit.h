#ifndef DEVICEEDIT_H
#define DEVICEEDIT_H

#include <QWidget>
#include <QSqlDatabase>


namespace Ui {
class DeviceEdit;
}

class DeviceEdit : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceEdit(QWidget *parent = nullptr);
    ~DeviceEdit();

    void receiveTableIndex(int serialNum);

private slots:
//    void on_pushButton_clicked();

//    void on_pushButton_2_clicked();

private:
    Ui::DeviceEdit *ui;
    QSqlDatabase dbd;
    void loadData(int serialNum);
    void populateForm(QSqlQuery& query);
};

#endif // DEVICEEDIT_H
