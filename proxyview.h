#ifndef PROXYVIEW_H
#define PROXYVIEW_H

#include <QAbstractItemModel>
#include <QAbstractTableModel>
#include <QVector>
#include <QVariant>
#include <DatabaseConnection.h>



class ProxyView : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit ProxyView(QObject *parent = nullptr);
    void setSearchParameters(const QString &searchParam, const QString &searchText);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override;

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    // Fetch data dynamically:
    bool hasChildren(const QModelIndex &parent = QModelIndex()) const override;

//    bool canFetchMore(const QModelIndex &parent) const override;
    void fetchMore(const QModelIndex &parent) override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    // Add data:
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

    // Remove data:
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

private:
    void loadData(QString searchParam, QString searchText);
    QString m_searchParam;
    QString m_searchText;
    QVector<QVector<QVariant>> rows;
    QVector<QString> columns;
    DatabaseConnection& dbConnection = DatabaseConnection::getInstance();


};

#endif // PROXYVIEW_H
