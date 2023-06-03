#ifndef TESTSECTION_H
#define TESTSECTION_H

#include <QObject>
#include <QMap>
#include "common/items/AbstractTextElement.h"

#include "common/items/Question.h"

/**
 * @brief The TestSection class
 * Так как подразумевается, что тест будет разделен
 * на секции, в которых содержатся вопросы, то
 * эта сущность описывает секцию вопросов
 */
class TestSection : public QObject, public AbstractTextElement {

    Q_OBJECT

    public:
        explicit TestSection(QString text, QMap<int, Question> questionList, bool hasImage = false, QString imagePath = "", QObject *parent = nullptr);
        TestSection(const TestSection& other);

        TestSection& operator=(const TestSection& other);
        virtual bool operator==(const TestSection& other) const;
        virtual bool operator!=(const TestSection& other) const;
        virtual bool operator<(const TestSection& other) const;
        virtual bool operator>(const TestSection& other) const;

    private:
        QMap<int, Question> questions;


    signals:

};

#endif // TESTSECTION_H
