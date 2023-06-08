#include "InitModule.h"

InitModule::InitModule(QObject *parent) : QObject(parent) {
}

void InitModule::init() {
    window = new MainWindow();
    database = new Database();
    logic = new ApplicationLogic();
    uiController = new UIController();

    ///Подтянуть с диска БД
    database->load();
    ///Загрузить в логику тесты
    logic->setAvailableTests(database->getAllTests());

    uiController->setUI(window);

    uiController->init();

}

void InitModule::connect() {

    QObject::connect(logic, &ApplicationLogic::signalAskQuestion, uiController, &UIController::onAskQuestion);
    QObject::connect(logic, &ApplicationLogic::signalShowTorstonResult, uiController, &UIController::onShowTorstonResult);
    QObject::connect(logic, &ApplicationLogic::signalShowLiriResult, uiController, &UIController::onShowLiriResult);
    QObject::connect(logic, &ApplicationLogic::signalUpdateProgressBar, uiController, &UIController::onUpdateProgressBar);


    QObject::connect(uiController, &UIController::signalOpenTest, logic, &ApplicationLogic::onTestSelected);
    QObject::connect(uiController, &UIController::signalStartTest, logic, &ApplicationLogic::onTestStarted);
    QObject::connect(uiController, &UIController::signalQuestAnsweredLiri, logic, &ApplicationLogic::onQuestAnsweredLiri);
    QObject::connect(uiController, &UIController::signalQuestAnsweredTorson, logic, &ApplicationLogic::onQuestAnsweredTorson);
    QObject::connect(uiController, &UIController::signalAbortTest, logic, &ApplicationLogic::onTestAborted);
    QObject::connect(uiController, &UIController::signalCompleteTest, logic, &ApplicationLogic::onTestEnded);

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
