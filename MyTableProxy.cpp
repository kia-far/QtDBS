#include "MyTableProxy.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>


MyTableProxy::MyTableProxy(const QStringList &customColumnNames, const QSqlDatabase &db, QObject *parent)
    : QAbstractTableModel(parent), customColumnNames(customColumnNames), db(db) {
    // Constructor body
}

void MyTableProxy::loadData(const QString &queryStr) {
    QSqlQuery query(db);
    if (!query.exec(queryStr)) {
        qWarning() << "Database query failed:" << query.lastError();
        return;
    }

    QSqlRecord record = query.record();
    int numCols = record.count();

    rows.clear();
    columns.clear();

    // Fetch all rows and columns
    while (query.next()) {
        QVector<QVariant> row;
        for (int i = 0; i < numCols; ++i) {
            row.append(query.value(i));
        }
        rows.append(row);
    }

    // Populate column names: first 4 from customColumnNames, rest from the database
    for (int i = 0; i < numCols; ++i) {
        if (i < customColumnNames.size()) {
            columns.append(customColumnNames.at(i));
        } else {
            columns.append(record.fieldName(i));  // Use database column names for the rest
        }
    }

    emit layoutChanged();
}

QVariant MyTableProxy::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole) {
        return QVariant();
    }

    if (orientation == Qt::Horizontal) {
        if (section < columns.size()) {
            return columns.at(section);
        }
    }

    return QVariant();
}

int MyTableProxy::rowCount(const QModelIndex &parent) const {
    if (parent.isValid()) {
        return 0;
    }
    return rows.size();
}

int MyTableProxy::columnCount(const QModelIndex &parent) const {
    if (parent.isValid()) {
        return 0;
    }
    return columns.size();
}

QVariant MyTableProxy::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }

    int row = index.row();
    int column = index.column();

    if (row >= rows.size() || column >= columns.size()) {
        return QVariant();  // Out of bounds
    }

    return rows.at(row).at(column);
}
