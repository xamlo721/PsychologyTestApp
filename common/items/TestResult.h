#ifndef TESTRESULT_H
#define TESTRESULT_H

#include <QObject>

#include "common/items/AbstractTextElement.h"

class TestResult : public QObject, public AbstractTextElement {

    Q_OBJECT

    public:
        TestResult(QString text, bool hasImage = false, QString imagePath = "", QObject *parent = nullptr);
        TestResult(const TestResult& other);
        TestResult& operator=(const TestResult& other);
        bool operator==(const TestResult& other) const;
        bool operator!=(const TestResult& other) const;

    signals:

};

#endif // TESTRESULT_H
