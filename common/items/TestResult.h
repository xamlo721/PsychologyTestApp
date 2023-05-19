#ifndef TESTRESULT_H
#define TESTRESULT_H

#include <QObject>

#include "common/items/AbstractTextElement.h"

class TestResult : public QObject, public AbstractTextElement {

    Q_OBJECT

    public:
        TestResult(QObject *parent = nullptr);

    signals:

};

#endif // TESTRESULT_H
