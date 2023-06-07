#include "UIController.h"

UIController::UIController(QObject *parent) : QObject(parent) {

}

void UIController::init() {

    //TODO: Проверить на наличие окна

    QObject::connect(window, &MainWindow::signalSelectTest, this, &UIController::signalOpenTest);
    QObject::connect(window, &MainWindow::signalTestStarted, this, &UIController::signalStartTest);

}

void UIController::setUI(MainWindow * window) {
    this->window = window;
}

void UIController::onAskQuestion(EnumTestType testType, Question q) {

    if (testType == EnumTestType::Liri) {
        this->window->ui_window->questLiri->uiQuestionsLiri->label_question->setText(q.getText());
        //TODO: Картинки молчат
    } else {
        this->window->ui_window->questTorson->uiQuestionsTorston->label_question->setText(q.getText());
        //TODO: Картинки молчат
    }

}

void UIController::onShowResult(TestResult result) {

}

void UIController::onUpdateProgressBar(float completePercent) {
    this->window->ui_window->questLiri->uiQuestionsLiri->progressBar->setValue(completePercent);
}
