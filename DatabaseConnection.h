#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <QSqlDatabase>
#include <QObject>
#include <QSqlError>
#include <QString>
#include <QDebug>

class DatabaseConnection : public QObject {
    Q_OBJECT

public:
    explicit DatabaseConnection();
    ~DatabaseConnection();

    static DatabaseConnection& getInstance();

    QSqlDatabase& getConnection() {
        return db;
    }

    bool openDatabase(const QString& dbName);
    void closeDatabase();
    QSqlError lastError() const;

private:
    DatabaseConnection(DatabaseConnection const&) = delete;
    void operator=(DatabaseConnection const&) = delete;

    QSqlDatabase db;
};

#endif // DATABASECONNECTION_H
