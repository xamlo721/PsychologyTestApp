#include "TestInstruction.h"

TestInstruction::TestInstruction(QString text, bool hasImage, QString imagePath, QObject *parent)
    : QObject(parent), AbstractTextElement(text, hasImage, imagePath) {

}
