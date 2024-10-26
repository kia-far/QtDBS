#ifndef DELETEOPTION_H
#define DELETEOPTION_H

#include <QWidget>

namespace Ui {
class DeleteOption;
}

class DeleteOption : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteOption(QWidget *parent = nullptr);
    void Setup(QString device,QString item);
    ~DeleteOption();

signals:
    void refresh(QString device);
private slots:
    void on_pushButton_clicked();

private:
    Ui::DeleteOption *ui;
    QString device;
    QString item;
    QStringList setupOptions(QString device,QString item);
    void Submit(QString device, QString item);
};

#endif // DELETEOPTION_H
