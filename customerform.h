#ifndef CUSTOMERFORM_H
#define CUSTOMERFORM_H

#include <QWidget>
#include <QSqlDatabase>
#include <memory>
#include <DatabaseConnection.h>


class QSqlDatabase;
namespace Ui {
class CustomerForm;

}

class CustomerForm : public QWidget
{
    Q_OBJECT

public:
    explicit CustomerForm(QWidget *parent = nullptr);
    ~CustomerForm();
    void init() const;
    void regOn();
    void regSubmit();
    void editOn(int serial);
    void editSubmit();
    void setup();
    void trigger(int serialnum);
    void addTrigger();


private slots:
    void on_pushButton_clicked();


private:
    Ui::CustomerForm *ui;
    void keyBinds();
//    QSqlDatabase db;
    QString Modee;
    QString b[5];
    int ID;
    DatabaseConnection &db;


};

#endif // CUSTOMERFORM_H
