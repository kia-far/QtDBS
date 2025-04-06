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
    void editOn(unsigned int serial);
    void editSubmit();
    void setup();
    void trigger(unsigned int serialnum);
    void addTrigger();

signals:
    void callPageRefresh();
    void callHelpPop(QString text);

private slots:
    void on_pushButton_clicked();
    void showHelpPop();
private:
    Ui::CustomerForm *ui;
    void keyBinds();
//    QSqlDatabase db;
    QString Modee;
    QString b[5];
    unsigned int ID;
    DatabaseConnection &db;
    void updateCustomerNames(QString newName);
    QString oldCustomerName;
    void keyPressEvent(QKeyEvent *event) override;

};

#endif // CUSTOMERFORM_H
