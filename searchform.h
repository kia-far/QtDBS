#ifndef SEARCHFORM_H
#define SEARCHFORM_H

#include <QWidget>

namespace Ui {
class SearchForm;
}

class SearchForm : public QWidget
{
    Q_OBJECT

public:
    explicit SearchForm(QWidget *parent = nullptr);
    void createCombo();
    void receiveTableIndex(int current);
    void refresh(int current);
    ~SearchForm();
signals:
    void searchWorking(QString searchparam,QString searchText);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_lineEdit_returnPressed();

private:
    Ui::SearchForm *ui;
};

#endif // SEARCHFORM_H
