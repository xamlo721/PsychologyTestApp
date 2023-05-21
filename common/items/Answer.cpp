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
