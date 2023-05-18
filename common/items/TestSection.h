#ifndef TESTSECTION_H
#define TESTSECTION_H

#include <QObject>

class TestSection : public QObject {

    Q_OBJECT

    public:
        explicit TestSection(QObject *parent = nullptr);

    signals:

};

#endif // TESTSECTION_H
