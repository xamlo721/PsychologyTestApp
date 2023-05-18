#ifndef INITMODULE_H
#define INITMODULE_H

#include <QObject>

#include "common/ui/MainWindow.h"
#include "common/logic/Database.h"
#include "common/logic/ApplicationLogic.h"
#include "common/controller/UIController.h"

class InitModule : public QObject {

    Q_OBJECT

    public:
        explicit InitModule(QObject *parent = nullptr);

        ~InitModule();

        void init();

        void connect();

        void launch();

    private:
        MainWindow * window;
        Database * database;
        ApplicationLogic * logic;
        UIController * uiController;

    signals:

};

#endif // INITMODULE_H
