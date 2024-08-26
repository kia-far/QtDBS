#include "DatabaseConnection.h"

// Singleton instance function
DatabaseConnection::DatabaseConnection() {
    openDatabase("C:\\Users\\kiafa\\Desktop\\Job\\DB\\sqlitestudio_x64-3.4.4\\SQLiteStudio\\InfoDB");
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
