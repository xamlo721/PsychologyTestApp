#include "UIController.h"
#include "common/ui/test/EnumAvailableTestWidgets.h"

UIController::UIController(QObject *parent) : QObject(parent) {

}

void UIController::init() {

    //TODO: Проверить на наличие окна

    QObject::connect(window->ui->testWidget, &MainTestWidget::signalSelectTest, this, &UIController::signalOpenTest);
    QObject::connect(window->ui->testWidget, &MainTestWidget::signalTestStarted, this, &UIController::signalStartTest);
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
void UIController::onShowLiriResult(int st1, int st2,int st3,int st4,int st5,int st6,int st7,int st8) {
    this->window->ui->testWidget->ui->stackedWidget->setCurrentIndex(EnumAvailableTestWidgets::ResultLiri);//Костыль
    this->window->ui->testWidget->ui->questResult->displayRadar(st1, st2,st3,st4,st5,st6,st7,st8);
}



void UIController::onUpdateProgressBar(float completePercent) {
    this->window->ui->testWidget->ui->questLiri->uiQuestionsLiri->progressBar->setValue(completePercent * 100);
    this->window->ui->testWidget->ui->questTorson->uiQuestionsTorston->progressBar->setValue(completePercent * 100);
}
