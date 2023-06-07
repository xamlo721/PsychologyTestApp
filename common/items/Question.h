#ifndef QUESTION_H
#define QUESTION_H

#include <QObject>
#include <QMap>

#include "common/items/Answer.h"
#include "common/items/AbstractTextElement.h"

class Question : public QObject, public AbstractTextElement {

    Q_OBJECT

    public:

        Question(QString text, QMap<int, Answer> answers, bool hasImage = false, QString imagePath = "",  QObject *parent = nullptr);
        Question(const Question& other);
        Question() : AbstractTextElement("") { }

        Question& operator=(const Question& other);
        virtual bool operator==(const Question& other) const;
        virtual bool operator!=(const Question& other) const;
        virtual bool operator<(const Question& other) const;
        virtual bool operator>(const Question& other) const;

        QMap<int, Answer> getAnswers();

    private:
        QMap <int, Answer> answers;

    signals:

};

#endif // QUESTION_H
