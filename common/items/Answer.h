#ifndef ANSWER_H
#define ANSWER_H

#include <QObject>

#include "common/items/AbstractTextElement.h"

class Answer : public QObject, public AbstractTextElement {

    Q_OBJECT

    public:
        Answer(QString text, bool isValid, bool hasImage = false, QString picturePath = "", QObject *parent = nullptr);
        Answer(const Answer &other);
        Answer() : AbstractTextElement("") { } //idk, just shit

        Answer& operator=(const Answer& other);
        virtual bool operator==(const Answer& other) const;
        virtual bool operator!=(const Answer& other) const;
        virtual bool operator<(const Answer& other) const;
        virtual bool operator>(const Answer& other) const;

        bool isTrue();

    signals:

    private:
        bool isValid;

};

#endif // ANSWER_H
