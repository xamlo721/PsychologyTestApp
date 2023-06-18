#include "UIController.h"

UIController::UIController(QObject *parent) : QObject(parent) {

}

void UIController::init() {

    //TODO: Проверить на наличие окна

    QObject::connect(window, &MainWindow::signalSelectTest, this, &UIController::signalOpenTest);
    QObject::connect(window, &MainWindow::signalTestComplete, this, &UIController::signalCompleteTest);
    QObject::connect(window, &MainWindow::signalTestAborted, this, &UIController::signalAbortTest);

    QObject::connect(window, &MainWindow::signalTestStarted, this, &UIController::signalStartTest);
    QObject::connect(window, &MainWindow::signalAuthUser, this, &UIController::onAuthUser);
    QObject::connect(window, &MainWindow::signalAddUser, this, &UIController::onAddUser);
    QObject::connect(window, &MainWindow::signalEditUser, this, &UIController::onEditUser);
    QObject::connect(window, &MainWindow::signalDeleteUser, this, &UIController::onDeleteUser);

    QObject::connect(window, &MainWindow::signalLiriAnswered, this, &UIController::signalQuestAnsweredLiri);
    QObject::connect(window, &MainWindow::signalTorstonAnswered, this, &UIController::signalQuestAnsweredTorson);
}

void UIController::setUI(MainWindow * window) {
    this->window = window;
}

void UIController::onAuthUser(UserAccount user) {
    emit signalAuthUser(user);
}

void UIController::onAddUser(QString user) {
    emit signalAddUser(user);

}

void UIController::onEditUser(UserAccount user) {
    emit signalEditUser(user);

}

void UIController::onDeleteUser(UserAccount user) {
    emit signalDeleteUser(user);

}


void UIController::onAskQuestion(EnumTestType testType, Question q) {

    if (testType == EnumTestType::Liri) {
        //TODO: Картинки молчат
        this->window->changeLiriQuestion(q);
    } else {
        this->window->changeTorstonQuestion(q);
    }

}

void UIController::onShowTorstonResult(TorstonResult result) {
    this->window->displayTorstonResult(result);

}
void UIController::onShowLiriResult(LiriResult result) {
    this->window->displayLiriResult(result);
}



void UIController::onUpdateProgressBar(float completePercent) {
    this->window->updateProgressBar(completePercent);
}

void UIController::onUpdateUserList(QList<UserAccount> users) {
    this->window->syncUserList(users);
}

void UIController::onUpdateResultsList(QMap <UserAccount, QPair<QList<LiriResult>, QList<TorstonResult>>> results) {
    this->window->syncResultsList(results);
}
