#include "Question.h"

Question::Question(QString text, QMap<int, Answer> answers, bool hasImage, QString imagePath, QObject *parent) : QObject(parent), AbstractTextElement(text, hasImage, imagePath) {
    this->text = text;
    this->answers = answers;
}

Question::Question(const Question& other)
    : QObject(other.parent()), AbstractTextElement(other), answers(other.answers) {


}

Question& Question::operator=(const Question& other) {
    if (&other == this) {
        return *this;
    }
    this->text = other.text;
    this->hasImage = other.hasImage;
    if(other.hasImage) {
        this->picturePath = other.picturePath;
    }
    this->answers = other.answers;
    return *this;
}

bool Question::operator==(const Question& other) const {
    return (text == other.text &&
            hasImage == other.hasImage &&
            picturePath == other.picturePath &&
            answers == other.answers);
}

bool Question::operator!=(const Question& other) const {
    return !(*this == other);
}

bool Question::operator<(const Question& other) const {
    return this->id < other.id;
}

bool Question::operator>(const Question& other) const {
    return this->id > other.id;
}


QMap<int, Answer> Question::getAnswers() {
    return this->answers;
}
