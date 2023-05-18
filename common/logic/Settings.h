#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>

class Settings : public QObject {

    Q_OBJECT

    public:
        explicit Settings(QObject *parent = nullptr);

    signals:

};

#endif // SETTINGS_H
