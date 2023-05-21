#include "TestSection.h"

TestSection::TestSection(QObject *parent) : QObject(parent) {

}

TestSection::TestSection(const TestSection& other) : QObject(other.parent()) {

}

TestSection& TestSection::operator=(const TestSection& other) {
    if (&other == this) {
        return *this;
    }

    QObject::setParent(other.parent());

    return *this;
}

bool TestSection::operator==(const TestSection& other) const {
    return questions == other.questions;
}

bool TestSection::operator!=(const TestSection& other) const {
    return !(*this == other);
}
