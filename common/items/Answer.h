#ifndef ANSWER_H
#define ANSWER_H

#include <QObject>

class Answer : public QObject {

    Q_OBJECT

    public:
        explicit Answer(QObject *parent = nullptr);

    signals:

};

#endif // ANSWER_H
