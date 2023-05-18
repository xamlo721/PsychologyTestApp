#include <QApplication>

#include "common/InitModule.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    InitModule boot;
    boot.init();
    boot.connect();
    boot.launch();

    return a.exec();
}
