#ifndef ANSWER_H
#define ANSWER_H

#include <QObject>

#include "common/items/AbstractTextElement.h"

class Answer : public QObject, public AbstractTextElement {

    Q_OBJECT

    public:
        Answer(QObject *parent = nullptr);
        Answer(const Answer &other);

    signals:

};

#endif // ANSWER_H
