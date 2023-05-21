#ifndef TESTINSTRUCTION_H
#define TESTINSTRUCTION_H

#include <QObject>

#include "common/items/AbstractTextElement.h"

class TestInstruction : public QObject, public AbstractTextElement {

    Q_OBJECT

    public:
        TestInstruction(QString text, bool hasImage = false, QString imagePath = "", QObject *parent = nullptr);

};

#endif // TESTINSTRUCTION_H
