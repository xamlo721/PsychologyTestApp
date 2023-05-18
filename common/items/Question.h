#ifndef QUESTION_H
#define QUESTION_H

#include <QObject>

class Question : public QObject {

    Q_OBJECT

    public:
        explicit Question(QObject *parent = nullptr);

    signals:

};

#endif // QUESTION_H
