#include "UIController.h"

UIController::UIController(QObject *parent) : QObject(parent) {

}

void UIController::init() {

}

void UIController::setUI(MainWindow * window) {
    this->window = window;
}

void UIController::onAskQuestion(Question q) {

}

void UIController::onShowResult(TestResult result) {

}

void UIController::onUpdateProgressBar(float completePercent) {
    this->window->ui_window->questLiri->uiQuestionsLiri->progressBar->setValue(completePercent);
}
