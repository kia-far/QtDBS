#include "productproxy.h"
#include "myfunctions.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>




ProductProxy::ProductProxy(QObject *parent)
    : QAbstractTableModel(parent),  m_searchParam("ProductInfo.SerialNO"), m_searchText(""), rows(), columns(),
      db(DatabaseConnection::getInstance())
{
    loadData(m_searchParam, m_searchText);
}
void ProductProxy::setSearchParameters(const QString &searchParam, const QString &searchText)
{
    m_searchParam = searchParam;
    m_searchText = searchText;
    loadData(m_searchParam,m_searchText);
}

void ProductProxy::sort(int column, Qt::SortOrder order) {
    if (column < 0 || column >= columnCount()) {
        return;  // Invalid column
    }

    // Lambda function to compare rows based on the given column
    std::sort(rows.begin(), rows.end(), [column, order](const QVector<QVariant> &a, const QVector<QVariant> &b) {
        if (order == Qt::AscendingOrder) {
            return a[column] < b[column];  // Ascending order comparison
        } else {
            return a[column] > b[column];  // Descending order comparison
        }
    });

    emit dataChanged(index(0, 0), index(rowCount() - 1, columnCount() - 1));
    emit layoutChanged();  // Notify view about the sorted data
}

void ProductProxy::loadData(QString searchParam,QString searchText) {


    QSqlQuery query(db.getConnection());
    QString res;
    QString context;
    QString space;
    if (searchParam=="ProductInfo.SerialNO"){

        res = MyFunctions::searchHandler("ProductInfo.*, ProductSecInfo.GuarantyExp, ProductSecInfo.PurchaseDate, ProductSecInfo.Description", "ProductInfo INNER JOIN ProductSecInfo ON ProductInfo.SerialNO = ProductSecInfo.SerialNO", searchParam,searchText);
    }
    else {res = "SELECT ProductInfo.*, ProductSecInfo.GuarantyExp, ProductSecInfo.PurchaseDate, ProductSecInfo.Description FROM ProductInfo INNER JOIN ProductSecInfo ON ProductInfo.SerialNO = ProductSecInfo.SerialNO WHERE "+searchParam+" LIKE '%"+searchText+"%'";}


    query.exec(res);
//    qDebug() << res;
    QSqlRecord record = query.record();
    int numCols = record.count();

    rows.clear();
    columns.clear();

    while (query.next()) {
        QVector<QVariant> row;
        for (int i = 0; i < numCols; ++i) {
            row.append(query.value(i));
        }
        rows.append(row);
    }

    if (!rows.isEmpty()) {
        // Convert the first column using intToStr()
        for (int i = 0; i < rows.size(); ++i) {
            rows[i][0] = MyFunctions::intToStr(rows[i][0].toInt());
        }

        // Add custom column headers
        // Replace these names with your desired names
        QStringList columnNames = {
            "شماره سریال", "نام محصول", "فاکتور", "شماره anydesk", "انقضای گارانتی", "تاریخ خرید", "توضیحات"
        };

        // Add column names
        for (const QString &name : columnNames) {
            columns.append(name);
        }
    }

//    qDebug() << "Rows loaded:" << rows.size();
//    qDebug() << "Columns loaded:" << columns.size();

    emit layoutChanged();
}

QVariant ProductProxy::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole) {
        return QVariant();
    }
    if (orientation == Qt::Horizontal) {
        return columns.at(section);
    } else {
        return QString::number(section + 1);
    }
}

bool ProductProxy::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role) {
    if (orientation == Qt::Horizontal && role == Qt::EditRole) {
        if (section >= 0 && section < columns.size()) {
            columns[section] = value.toString();
            emit headerDataChanged(orientation, section, section);
            return true;
        }
    }
    return false;
}

QModelIndex ProductProxy::index(int row, int column, const QModelIndex &parent) const {
    if (!hasIndex(row, column, parent)) {
        return QModelIndex();
    }
    return createIndex(row, column);
}

QModelIndex ProductProxy::parent(const QModelIndex &index) const {
    return QModelIndex();
}

int ProductProxy::rowCount(const QModelIndex &parent) const {
    if (parent.isValid()) {
        return 0;
    }
    return rows.size();
}

int ProductProxy::columnCount(const QModelIndex &parent) const {
    if (parent.isValid()) {
        return 0;
    }
    return columns.size();
}

bool ProductProxy::hasChildren(const QModelIndex &parent) const {
    return !parent.isValid() ? rowCount(parent) > 0 : false;
}

bool ProductProxy::canFetchMore(const QModelIndex &parent) const {
    return false;
}

void ProductProxy::fetchMore(const QModelIndex &parent) {
    // No additional data to fetch
}

QVariant ProductProxy::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }

    int row = index.row();
    int column = index.column();

    if (row >= rows.size() || column >= columns.size()) {
        qDebug() << "Index out of bounds: row" << row << "column" << column;
        return QVariant();
    }

    return rows.at(row).at(column);
}

bool ProductProxy::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (data(index, role) != value) {
        rows[index.row()][index.column()] = value;
        emit dataChanged(index, index, QVector<int>() << role);
        if(index.row()%2==0){

        }
        return true;
    }
    return false;
}

Qt::ItemFlags ProductProxy::flags(const QModelIndex &index) const {
    if (!index.isValid()) {
        return Qt::NoItemFlags;
    }
    return Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable;
}

bool ProductProxy::insertRows(int row, int count, const QModelIndex &parent) {
    beginInsertRows(parent, row, row + count - 1);
    rows.insert(row, count, QVector<QVariant>(columnCount()));
    endInsertRows();
    return true;
}




bool ProductProxy::insertColumns(int column, int count, const QModelIndex &parent) {
    beginInsertColumns(parent, column, column + count - 1);
    for (auto &row : rows) {
        row.insert(column, count, QVariant());
    }
    endInsertColumns();
    return true;
}

bool ProductProxy::removeRows(int row, int count, const QModelIndex &parent) {
    beginRemoveRows(parent, row, row + count - 1);
    rows.remove(row, count);
    endRemoveRows();
    return true;
}

bool ProductProxy::removeColumns(int column, int count, const QModelIndex &parent) {
    beginRemoveColumns(parent, column, column + count - 1);
    for (auto &row : rows) {
        row.remove(column, count);
    }
    endRemoveColumns();
    return true;
}
