#include "DatabaseConnection.h"
#include <QApplication>
// Singleton instance function
DatabaseConnection::DatabaseConnection() {
    QString addr = qApp->applicationDirPath();

    openDatabase(addr+"/DB/InfoDB");
}

DatabaseConnection::~DatabaseConnection() {
    closeDatabase();
}

DatabaseConnection& DatabaseConnection::getInstance() {
    static DatabaseConnection instance; // Guaranteed to be destroyed.
    return instance;                    // Instantiated on first use.
}

bool DatabaseConnection::openDatabase(const QString &dbName) {
    if (db.isOpen()) {
        return true; // Already open
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(dbName);

        if (!db.open()) {
            qDebug() << "Failed to open database:" << db.lastError().text();
            return false;
        }
    }
    return true;
}

void DatabaseConnection::closeDatabase() {
    if (db.isOpen()) {
        db.close();
        QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
    }
}

QSqlError DatabaseConnection::lastError() const {
    return db.lastError();
}
