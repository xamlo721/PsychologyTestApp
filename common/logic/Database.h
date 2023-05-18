#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>

#include "common/items/EnumTestType.h"
#include "common/items/EnumDatabaseType.h"

class Database : public QObject {

    Q_OBJECT
    private:
        static const EnumDatabaseType defaultDatabaseType  = EnumDatabaseType::XML;

    public:
        explicit Database(QObject *parent = nullptr);

        ~Database();

        EnumDatabaseType getDatabaseType();

        void setDatabaseType(EnumDatabaseType type);

        void readDatabase();

        void getDatabase();

    private:

        EnumDatabaseType testType;

    signals:

};

#endif // DATABASE_H
