#include "productproxy.h"
#include "myfunctions.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include "itemhandler.h"
#include "logger.h"


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

void ProductProxy::loadData(QString searchParam, QString searchText) {
    QSqlQuery query(db.getConnection());
    QString res;
    QStringList productNames = ItemHandler::loadDevices();  // Get the list of all device names

    // Debug output to check the product names
    // qDebug() << "List of device names:" << productNames;

    // Step 1: Clear existing rows and columns
    rows.clear();
    columns.clear();

    // Step 2: Loop through each product/device name to build and execute a query
    foreach (const QString &productName, productNames) {
        // Dynamically construct the main query for each product
        if (searchParam == "ProductInfo.SerialNO") {
            res = MyFunctions::searchHandler(
                " ProductInfo.*, "
                    + productName + ".CustomerName ",
                " ProductInfo "
                " INNER JOIN " + productName + " ON " + productName + ".SerialNumber = ProductInfo.SerialNO",
                searchParam, searchText);
        } else {
            res = "SELECT ProductInfo.* ," + productName + ".CustomerName "
                                  " FROM ProductInfo "
                                  " INNER JOIN " + productName + " ON " + productName + ".SerialNumber = ProductInfo.SerialNO "
                                                         "WHERE " + searchParam + " LIKE '%" + searchText + "%'";
        }

        // Step 3: Execute the dynamically constructed query
        if (!query.exec(res)) {
            qWarning() << "Failed to execute query for product: " << productName << query.lastError();
            continue;  // Skip to the next product if this query fails
        }

        // Step 4: Process the result and load data into the rows and columns
        QSqlRecord record = query.record();
        int numCols = record.count(); // Get the number of columns in the result

        while (query.next()) {
            QVector<QVariant> row;

            // Populate the row with the query results in the original order
            for (int i = 0; i < numCols; ++i) {
                row.append(query.value(i)); // Append each value
            }

            // Rearrange the columns to place "Customer Name" at the third position
            if (numCols > 3) {
                QVariant customerName = row.takeLast(); // Assuming CustomerName is the last column
                row.insert(2, customerName); // Insert Customer Name as the third column
            }

            rows.append(row); // Add the rearranged row to the list
        }
    }

    // Step 5: If there is data, convert the first column and set up column headers
    if (!rows.isEmpty()) {
        // Convert the first column (Serial Number) using intToStr()
        for (int i = 0; i < rows.size(); ++i) {
            rows[i][0] = MyFunctions::intToStr(rows[i][0].toUInt());
        }

        // Add custom column headers (adjust based on the shared and dynamically added columns)
        QStringList columnNames = {
            "شماره سریال",  // Serial Number
            "نام محصول",    // Product Name
            "نام مشتری",      // Customer Name (Dynamically added from the product-specific table)
            "فاکتور",       // Invoice
            "شماره anydesk", // Anydesk Number
            "تاریخ خرید",    // Purchase Date
            "انقضای گارانتی", // Warranty Expiration
            "توضیحات"      // Description
        };

        for (const QString &name : columnNames) {
            columns.append(name); // Append each column name to the columns list
        }
    }
    logger::log( "data loaded for product info and product sec info!");
    // Notify the view that the layout has changed (data and columns have been updated)
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

    if (row >= rows.size() || row < 0 || column >= rows[row].size() || column < 0) {
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

void ProductProxy::searchSN(QString ST){
    if(ST.at(0).isLetter()){

    }
}
