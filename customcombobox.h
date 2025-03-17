#ifndef CUSTOMCOMBOBOX_H
#define CUSTOMCOMBOBOX_H

#include <QComboBox>
#include <QCompleter>
#include <QStringList>
#include <QStringListModel>

class CustomComboBox : public QComboBox {
    Q_OBJECT

public:
    explicit CustomComboBox(QWidget *parent = nullptr);
    void setCompleterData(const QStringList &items);

protected:
    void showPopup() override;  // Only override this function

private:
    QCompleter *completer;
    QStringList completerData;
};

#endif // CUSTOMCOMBOBOX_H
