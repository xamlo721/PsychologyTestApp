#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QMap>

#include "common/items/EnumTestType.h"
#include "common/items/TestResult.h"
#include "common/items/TestSection.h"
#include "common/items/Question.h"

class Test : public QObject {

    Q_OBJECT

    public:
        explicit Test(EnumTestType testType, QMap<int, TestSection> sections, TestResult testResult, QObject *parent = nullptr);
        Test(const Test& other);

        Test& operator=(const Test& other);
        bool operator==(const Test& other) const;
        bool operator!=(const Test& other) const;
        bool operator<(const Test& other) const;

        EnumTestType getTestType() const;

        TestResult getTestResult() const;

        QMap<int, TestSection> getSections();

    private:
        EnumTestType testType;

        TestResult testResult;

        QMap<int, TestSection> sections;

    signals:

};

#endif // TEST_H
