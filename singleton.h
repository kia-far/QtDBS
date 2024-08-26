#ifndef SINGLETON_H
#define SINGLETON_H

#include <QAbstractItemModel>
#include <QSqlDatabase>

class singleton : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit singleton(QObject *parent = nullptr);
    static QSqlDatabase db();

    // Header:

    /*
    class S
    {
        public:
            static S& getInstance()
            {
                static S    instance;
                return instance;
            }
        private:
            S() {}
            S(S const&);              // Don't Implement.
            void operator=(S const&); // Don't implement
     };*/

private:
};

#endif // SINGLETON_H
