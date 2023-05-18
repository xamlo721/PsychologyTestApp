#ifndef TESTRESULT_H
#define TESTRESULT_H

#include <QObject>

class TestResult : public QObject {

    Q_OBJECT

    public:
        explicit TestResult(QObject *parent = nullptr);

    signals:

};

#endif // TESTRESULT_H
