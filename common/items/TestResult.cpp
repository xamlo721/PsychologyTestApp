#include "TestResult.h"

TestResult::TestResult(QString text, bool hasImage, QString imagePath, QObject *parent)
    : QObject(parent) , AbstractTextElement(text, hasImage, imagePath) {

}

TestResult::TestResult(const TestResult& other)
    : QObject(other.parent()), AbstractTextElement(other.text, other.hasImage, other.picturePath) {

}

TestResult& TestResult::operator=(const TestResult& other) {
    if (&other == this)
        return *this;

    QObject::setParent(other.parent());

    return *this;
}

bool TestResult::operator==(const TestResult& other) const {
    return AbstractTextElement::operator ==(other);
}

bool TestResult::operator!=(const TestResult& other) const {
    return !(*this == other);
}
