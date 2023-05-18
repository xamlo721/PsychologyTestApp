#include "Database.h"

Database::Database(QObject *parent) : QObject(parent), testType(defaultDatabaseType){

}

EnumDatabaseType Database::getDatabaseType() {
    return this->testType;
}

void Database::setDatabaseType(EnumDatabaseType type) {
    this->testType = type;
}

void Database::readDatabase() {
    //TODO:
}

void Database::getDatabase() {
    //TODO:
}

Database::~Database() {

}
