#ifndef APPLICATIONLOGIC_H
#define APPLICATIONLOGIC_H

#include <QObject>

class ApplicationLogic : public QObject {

    Q_OBJECT

    public:
        explicit ApplicationLogic(QObject *parent = nullptr);

    signals:

};

#endif // APPLICATIONLOGIC_H
