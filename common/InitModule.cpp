#include "InitModule.h"

InitModule::InitModule(QObject *parent) : QObject(parent) {
}

void InitModule::init() {
    window = new MainWindow();
    database = new Database();
    logic = new ApplicationLogic();
    uiController = new UIController();
}

void InitModule::connect() {

}

void InitModule::launch() {
    window->show();

}

InitModule::~InitModule() {
    delete window;
    delete database;
    delete logic;
    delete uiController;
}
