#ifndef MYTABLEPROXY_H
#define MYTABLEPROXY_H

#include <QAbstractTableModel>
#include <QSqlDatabase>
#include <QStringList>
#include <QVector>

class MyTableProxy : public QAbstractTableModel {
    Q_OBJECT

public:
    explicit MyTableProxy(const QStringList &customColumnNames, const QSqlDatabase &db, QObject *parent = nullptr);
    void sort(int column, Qt::SortOrder order);
    // Method to load the data from the query
    void loadData(const QString &queryStr);
//    void sort(int column, Qt::SortOrder order);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    QSqlDatabase db;                  // Database connection
    QStringList customColumnNames;    // Custom column names
    QVector<QVector<QVariant>> rows;  // Table data
    QStringList columns;              // Column names from the database
};

#endif // MYTABLEPROXY_H
