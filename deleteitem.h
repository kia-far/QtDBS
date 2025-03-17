#ifndef DELETEITEM_H
#define DELETEITEM_H

#include <QWidget>
#include "DatabaseConnection.h"
#include <QListWidgetItem>

namespace Ui {
class DeleteItem;
}

class DeleteItem : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteItem(QWidget *parent = nullptr);
    void setup(QString device);
    QVector<unsigned int> checkItem(QString deviceName, QString itemName);
    ~DeleteItem();

signals:
    void refreshDevices(QString device);
    void refreshTable();
private slots:
    void on_pushButton_clicked();
    void on_listWidget_itemClicked(QListWidgetItem *item);
    bool deleteDone(QString device, QString item);
private:
    QString device;
    DatabaseConnection &db;
    QString item;
    Ui::DeleteItem *ui;
};

#endif // DELETEITEM_H
