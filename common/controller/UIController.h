#ifndef UICONTROLLER_H
#define UICONTROLLER_H

#include <QObject>

class UIController : public QObject {
    Q_OBJECT

    public:
        explicit UIController(QObject *parent = nullptr);

    signals:

};

#endif // UICONTROLLER_H
