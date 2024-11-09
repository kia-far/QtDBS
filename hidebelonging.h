#ifndef HIDEBELONGING_H
#define HIDEBELONGING_H

#include <QWidget>

namespace Ui {
class HideBelonging;
}

class HideBelonging : public QWidget
{
    Q_OBJECT

public:
    explicit HideBelonging(QWidget *parent = nullptr);
    void setup(QString device);
    void submitChanges(QString device);
    void closePage();
    ~HideBelonging();
signals:
    void refreshDevPage(QString device);
private slots:
    void on_pushButton_clicked();

private:
    Ui::HideBelonging *ui;
    QString device;
};

#endif // HIDEBELONGING_H
