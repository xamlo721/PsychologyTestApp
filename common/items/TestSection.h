#ifndef TESTSECTION_H
#define TESTSECTION_H

#include <QObject>
#include <QMap>

#include "common/items/Question.h"

/**
 * @brief The TestSection class
 * Так как подразумевается, что тест будет разделен
 * на секции, в которых содержатся вопросы, то
 * эта сущность описывает секцию вопросов
 */
class TestSection : public QObject {

    Q_OBJECT

    public:
        explicit TestSection(QObject *parent = nullptr);

    private:
        QMap<int, Question> questions;

    signals:

};

#endif // TESTSECTION_H
