#include "Question.h"

Question::Question(QString text, QMap<int, Answer> answers, QObject *parent) : QObject(parent) {
    this->text = text;
    this->answers = answers;
}

QMap<int, Answer> Question::getAnswers() {
    return this->answers;
}
