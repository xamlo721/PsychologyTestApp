#include "Database.h"
#include "common/logic/XMLHelper.h"
#include "common/logic/SQLHelper.h"

Database::Database(QObject *parent) : QObject(parent), databaseType(defaultDatabaseType){

}

EnumDatabaseType Database::getDatabaseType() {
    return this->databaseType;
}

void Database::setDatabaseType(EnumDatabaseType type) {
    this->databaseType = type;
}

void Database::load() {

    QList<Test *>tests;
    switch (this->databaseType) {

    case EnumDatabaseType::SQL : {
            //TODO:
            break;
        }
        case EnumDatabaseType::XML : {

            break;
        }
        default: {

            break;
        }
    }
}

Test* Database::getTest(EnumTestType testType) {

    Test * test = this->database.value(testType);
    //TODO: Проверить на наличие теста и бросить исключение
    return test;
}

Database::~Database() {

}
