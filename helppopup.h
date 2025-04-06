#ifndef HELPPOPUP_H
#define HELPPOPUP_H

#include <QWidget>

namespace Ui {
class helpPopUp;
}

class helpPopUp : public QWidget
{
    Q_OBJECT

public:
    explicit helpPopUp(QWidget *parent = nullptr);
    void setHelp(QString text);
    ~helpPopUp();

private slots:
    void on_pushButton_clicked();

private:
    Ui::helpPopUp *ui;
};

#endif // HELPPOPUP_H
