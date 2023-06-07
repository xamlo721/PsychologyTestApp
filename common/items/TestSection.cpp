#include "TestSection.h"

TestSection::TestSection(QString text, QMap<int, Question> questionList, bool hasImage, QString imagePath, QObject *parent) : QObject(parent), AbstractTextElement(text, hasImage, imagePath)  {
    this->questions = questionList;
}

TestSection::TestSection(const TestSection& other)
    : QObject(other.parent()),
      AbstractTextElement(other.text, other.hasImage, other.picturePath),
      questions(other.questions) {

}

QMap<int, Question> TestSection::getQuestions() {
    return this->questions;
}


TestSection& TestSection::operator=(const TestSection& other) {
    if (&other == this) {
        return *this;
    }
    this->text = other.text;
    this->hasImage = other.hasImage;
    if(other.hasImage) {
        this->picturePath = other.picturePath;
    }
    this->questions = other.questions;
    return *this;
}

bool TestSection::operator==(const TestSection& other) const {
    return (text == other.text &&
            hasImage == other.hasImage &&
            picturePath == other.picturePath &&
            questions == other.questions);
}

bool TestSection::operator!=(const TestSection& other) const {
    return !(*this == other);
}

bool TestSection::operator<(const TestSection& other) const {
    return this->id < other.id;
}

bool TestSection::operator>(const TestSection& other) const {
    return this->id > other.id;
}
