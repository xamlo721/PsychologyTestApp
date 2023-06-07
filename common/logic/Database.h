#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QMap>

#include "common/items/EnumTestType.h"
#include "common/items/EnumDatabaseType.h"
#include "common/items/Test.h"


class Database : public QObject {

    Q_OBJECT
    private:
        static const EnumDatabaseType defaultDatabaseType  = EnumDatabaseType::XML;

    public:
        explicit Database(QObject *parent = nullptr);

        ~Database();

        EnumDatabaseType getDatabaseType();

        void setDatabaseType(EnumDatabaseType type);

        void load();

        Test * getTest(EnumTestType testType);

        QMap<EnumTestType, Test *> getAllTests();

    private:

        EnumDatabaseType databaseType;

        //TODO: Заменить на хранение по значению
        QMap<EnumTestType, Test *> database;

    signals:

};

#endif // DATABASE_H
