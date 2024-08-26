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
    void editOn(int serial);
    void editSubmit();
    void setup();
    void trigger(int serialnum);
    void addTrigger();


private slots:
    void on_pushButton_clicked();


private:
    Ui::serviceEdit *ui;
//    QSqlDatabase db;
    QString Modee;
    QString b[6];
    int ID;
    DatabaseConnection &db;


};

#endif // SERVICEEDIT_H
