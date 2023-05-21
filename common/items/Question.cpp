#include "Question.h"

Question::Question(QString text, QMap<int, Answer> answers, bool hasImage, QString imagePath, QObject *parent) : QObject(parent), AbstractTextElement(text, hasImage, imagePath) {
    this->text = text;
    this->answers = answers;
}

QMap<int, Answer> Question::getAnswers() {
    return this->answers;
}
