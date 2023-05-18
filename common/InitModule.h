#ifndef INITMODULE_H
#define INITMODULE_H

#include <QObject>

class InitModule : public QObject {

    Q_OBJECT

    public:
        explicit InitModule(QObject *parent = nullptr);

    signals:

};

#endif // INITMODULE_H
