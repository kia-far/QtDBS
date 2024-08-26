#ifndef PRODUCTREGISTER_H
#define PRODUCTREGISTER_H

#include <QWidget>
#include <QSqlDatabase>
#include <DatabaseConnection.h>

namespace Ui {
class ProductRegister;
}

class ProductRegister : public QWidget
{
    Q_OBJECT

public:
    explicit ProductRegister(QWidget *parent = nullptr);
    ~ProductRegister();
    void regOn();
    void regSubmit();
    void editOn(int serial);
    void editSubmit();
    void setup();
    void trigger(int serialnum);
    void addTrigger();
    void loadProductInfo();
    void loadProductSecInfo();
    void updateProductInfo();
    void updateProductSecInfo();
    void registerProductInfo();
    void registerProductSecInfo();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ProductRegister *ui;
    QSqlDatabase db;
    QString Mode;
    int Serialnum;
    DatabaseConnection& dbConnection = DatabaseConnection::getInstance();

};

#endif // PRODUCTREGISTER_H
