#include "Answer.h"

Answer::Answer(QString text, bool hasImage, QString imagePath, QObject *parent) : QObject(parent) , AbstractTextElement(text, hasImage, imagePath) {

}
/**
 * @brief Answer::Answer контруктор копирования, для функционирования QMap<>
 * @param other
 */
Answer::Answer(const Answer &other) : QObject(other.parent()), AbstractTextElement(other.text, other.hasImage, other.picturePath) {
    // копирование значений переменных-членов класса
}

Answer& Answer::operator=(const Answer& other) {
    if (&other == this) {
        return *this;
    }
    this->text = other.text;
    this->hasImage = other.hasImage;
    if(other.hasImage) {
        this->picturePath = other.picturePath;
    }

    return *this;
}

bool Answer::operator==(const Answer& other) const {
    return (text == other.text &&
            hasImage == other.hasImage &&
            picturePath == other.picturePath);
}

bool Answer::operator!=(const Answer& other) const {
    return !(*this == other);
}

bool Answer::operator<(const Answer& other) const {
    return this->id < other.id;
}

bool Answer::operator>(const Answer& other) const {
    return this->id > other.id;
}
