#ifndef SERVICEEDIT_H
#define SERVICEEDIT_H

#include <QWidget>
#include <QSqlDatabase>
#include <DatabaseConnection.h>

namespace Ui {
class serviceEdit;
}

class serviceEdit : public QWidget
{
    Q_OBJECT

public:
    explicit serviceEdit(QWidget *parent = nullptr);
    ~serviceEdit();
    void regOn();
    void regSubmit();
    void editOn(unsigned int serial);
    void editSubmit();
    void setup();
    void trigger(unsigned int serialnum);
    void addTrigger();


private slots:
    void on_pushButton_clicked();


    void on_CustomerCombo_editTextChanged(const QString &arg1);
    // void on_ProductCombo_editTextChanged(const QString &arg1);

    void on_ProductCombo_editTextChanged(const QString &arg1);

private:
    Ui::serviceEdit *ui;
    void keyBinds();
    void populateCombo();
    QStringList getCustomers(QString halfText);
    QStringList getProducts(QString halfText);
//    QSqlDatabase db;
    QString Modee;
    QString b[8];
    unsigned int ID;
    DatabaseConnection &db;


};

#endif // SERVICEEDIT_H
