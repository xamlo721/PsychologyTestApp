#include "UIController.h"

UIController::UIController(QObject *parent) : QObject(parent) {

}

void UIController::init() {

    //TODO: Проверить на наличие окна

    QObject::connect(window->ui->testWidget, &MainTestWidget::signalSelectTest, this, &UIController::signalOpenTest);
    QObject::connect(window, &MainWindow::signalTestStarted, this, &UIController::signalStartTest);
    QObject::connect(window->ui->testWidget, &MainTestWidget::signalTestComplete, this, &UIController::signalCompleteTest);
    QObject::connect(window->ui->testWidget, &MainTestWidget::signalTestAborted, this, &UIController::signalAbortTest);

    QObject::connect(window->ui->testWidget->ui->questLiri, &QuestionLiriWidget::signalAnswerd, this, &UIController::signalQuestAnsweredLiri);
    QObject::connect(window->ui->testWidget->ui->questTorson, &QuestionTorsonWidget::signalAnswered, this, &UIController::signalQuestAnsweredTorson);
}

void UIController::setUI(MainWindow * window) {
    this->window = window;
}

void UIController::onAskQuestion(EnumTestType testType, Question q) {

    if (testType == EnumTestType::Liri) {
        this->window->ui->testWidget->ui->questLiri->uiQuestionsLiri->label_question->setText(q.getText());
        //TODO: Картинки молчат
    } else {
        this->window->ui->testWidget->ui->questTorson->uiQuestionsTorston->label_question->setText(q.getText());

        if (q.hasPicture()) {

            QString stylesheet = "QWidget#widget_picture {"
                                 "	background-image: url(:" + q.getPicturePath() +");\n"
                                 "}";
             this->window->ui->testWidget->ui->questTorson->uiQuestionsTorston->widget_picture->setStyleSheet(stylesheet);
        }
    }

}

void UIController::onShowTorstonResult(EnumTorsonResult result) {
    this->window->ui->testWidget->showResult(result);

}
void UIController::onShowLiriResult(LiriResult result) {
    this->window->displayLiriResult(result);
}



void UIController::onUpdateProgressBar(float completePercent) {
    this->window->ui->testWidget->ui->questLiri->uiQuestionsLiri->progressBar->setValue(completePercent * 100);
    this->window->ui->testWidget->ui->questTorson->uiQuestionsTorston->progressBar->setValue(completePercent * 100);
}
