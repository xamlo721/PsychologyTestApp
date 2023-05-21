#include "Database.h"

Database::Database(QObject *parent) : QObject(parent), testType(defaultDatabaseType){

}

EnumDatabaseType Database::getDatabaseType() {
    return this->testType;
}

void Database::setDatabaseType(EnumDatabaseType type) {
    this->testType = type;
}

void Database::load() {
    //TODO:
}

Test* Database::getTest(EnumTestType testType) {

    Test * test = this->database.value(testType);
    //TODO: Проверить на наличие теста и бросить исключение
    return test;
}

Database::~Database() {

}
