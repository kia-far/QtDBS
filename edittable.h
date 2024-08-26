#ifndef EDITTABLE_H
#define EDITTABLE_H

#include <QWidget>
#include <QSqlDatabase>
#include <DatabaseConnection.h>

namespace Ui {
class EditTable;
}

class ProductEdit;

class EditTable : public QWidget
{
    Q_OBJECT

public:
    explicit EditTable(QWidget *parent = nullptr);
    ~EditTable();

    void loadSerialNumber(int serialNum);
    void receiveTableIndex(int serialNum, int index);

private slots:
    void on_pushButton_clicked();

private:
    Ui::EditTable *ui;
    QSqlDatabase dbe;
    ProductEdit *model;
    DatabaseConnection& dbConnection = DatabaseConnection::getInstance();

};

#endif // EDITTABLE_H
