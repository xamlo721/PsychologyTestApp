#include "Test.h"

Test::Test(EnumTestType testType, QMap<int, TestSection> sections, TestResult testResult, QObject *parent)
    : QObject(parent), testType(testType), testResult(testResult),  sections(sections) {

}

Test::Test(const Test& other)
    : QObject(other.parent()), testType(other.testType), testResult(other.testResult),  sections(other.sections) {


}

Test& Test::operator=(const Test& other) {
    if (&other == this)
        return *this;

    QObject::setParent(other.parent());
    testType = other.testType;
    testResult = other.testResult;
    sections = other.sections;

    return *this;
}

bool Test::operator==(const Test& other) const {
    return (testType == other.testType &&
            sections == other.sections &&
            testResult == other.testResult);
}
bool Test::operator!=(const Test& other) const {
    return !(*this == other);
}
bool Test::operator<(const Test& other) const {
    //TODO:
    return false;
}



EnumTestType Test::getTestType() const {
    return testType;
}

TestResult Test::getTestResult() const {
    return testResult;
}
