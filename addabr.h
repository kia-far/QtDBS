#ifndef ADDABR_H
#define ADDABR_H

#include <QWidget>

namespace Ui {
class AddAbr;
}

class AddAbr : public QWidget
{
    Q_OBJECT

public:
    explicit AddAbr(QWidget *parent = nullptr);
    void setup();
    ~AddAbr();

private slots:
    void on_submitButton_clicked();

private:
    Ui::AddAbr *ui;
};

#endif // ADDABR_H
