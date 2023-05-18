#ifndef COREAPP_H
#define COREAPP_H

#include <QObject>

class CoreApp : public QObject {

    Q_OBJECT

    public:
        explicit CoreApp(QObject *parent = nullptr);

    signals:

};

#endif // COREAPP_H
