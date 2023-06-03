#include "AbstractTextElement.h"

int AbstractTextElement::counter = 0;

AbstractTextElement::AbstractTextElement(QString text, bool hasImage, QString imagePath) : id(counter++) {
    this->text = text;
    this->hasImage = hasImage;
    if (hasImage && imagePath.isEmpty()) {
        //TODO: Бросить исключение
    }
    this->picturePath = imagePath;
    this->id = AbstractTextElement::counter++;
}

QString AbstractTextElement::getText() {
    return this->text;
}

bool AbstractTextElement::hasPicture() {
    return this->hasImage;
}

QString AbstractTextElement::getPicturePath() {
    return this->picturePath;
}

AbstractTextElement& AbstractTextElement::operator=(const AbstractTextElement& other) {
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

bool AbstractTextElement::operator==(const AbstractTextElement& other) const {
    return (text == other.text &&
            hasImage == other.hasImage &&
            picturePath == other.picturePath);
}

bool AbstractTextElement::operator!=(const AbstractTextElement& other) const {
    return !(*this == other);
}

bool AbstractTextElement::operator<(const AbstractTextElement& other) const {
    return this->id < other.id;
}

bool AbstractTextElement::operator>(const AbstractTextElement& other) const {
    return this->id > other.id;
}
