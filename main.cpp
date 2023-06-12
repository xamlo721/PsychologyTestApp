#include <QApplication>

#include "common/InitModule.h"

class Application final: public QApplication{
    public:
        using QApplication::QApplication;
        bool notify(QObject *receiver, QEvent *e) override;


};

bool Application::notify(QObject* receiver, QEvent* event)
{
    try
    {
        return QApplication::notify(receiver, event);
    }
    catch (std::exception &e)
    {
        qFatal("Error %s sending event %s to object %s (%s)",
            e.what(), typeid(*event).name(), qPrintable(receiver->objectName()),
            typeid(*receiver).name());
    }
    catch (...)
    {
        qFatal("Error <unknown> sending event %s to object %s (%s)",
            typeid(*event).name(), qPrintable(receiver->objectName()),
            typeid(*receiver).name());
    }
    return false;
}



int main(int argc, char *argv[]) {
    Application a(argc, argv);
    InitModule boot;
    boot.init();
    boot.connect();
    boot.launch();


    return a.exec();
}
