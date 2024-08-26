#ifndef ITEMABSTRACT_H
#define ITEMABSTRACT_H

#include <QAbstractItemModel>

class ItemAbstract : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit ItemAbstract(QObject *parent = nullptr);

    // Header:


private:
};

#endif // ITEMABSTRACT_H
