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
        explicit Test(QObject *parent = nullptr);

    private:
        EnumTestType testType;

        TestResult testResult;

        QMap<int, TestSection> sections;

    signals:

};

#endif // TEST_H
