#include "AbstractTextElement.h"

QString AbstractTextElement::getText() {
    return this->text;
}

bool AbstractTextElement::hasPicture() {
    return this->hasImage;
}

QString AbstractTextElement::getPicturePath() {
    return this->picturePath;
}

