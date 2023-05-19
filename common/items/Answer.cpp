#include "Answer.h"

Answer::Answer(QObject *parent) : QObject(parent) {

}
/**
 * @brief Answer::Answer контруктор копирования, для функционирования QMap<>
 * @param other
 */
Answer::Answer(const Answer &other) : QObject(other.parent()), AbstractTextElement() {
    // копирование значений переменных-членов класса
}
