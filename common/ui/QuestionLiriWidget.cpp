#include "QuestionLiriWidget.h"

QuestionLiriWidget::QuestionLiriWidget(QWidget *parent) : QWidget(parent), uiQuestionsLiri(new Ui::QuestionsLiri) {
    uiQuestionsLiri->setupUi(this);
    QObject::connect(this->uiQuestionsLiri->NO, &QPushButton::clicked, this, &QuestionLiriWidget::onNoButtonClicked);
    QObject::connect(this->uiQuestionsLiri->YES, &QPushButton::clicked, this, &QuestionLiriWidget::onYesButtonClicked);
    QObject::connect(this->uiQuestionsLiri->ESC, &QPushButton::clicked, this, &QuestionLiriWidget::signalAborted);
    this->setFocusPolicy(Qt::StrongFocus);

}

void QuestionLiriWidget::setQuestion(QString question) {
    this->uiQuestionsLiri->info->setText(question);
}

void QuestionLiriWidget::onYesButtonClicked() {
    emit signalAnswerd(false);
}

void QuestionLiriWidget::onNoButtonClicked() {
    emit signalAnswerd(true);
}

void QuestionLiriWidget::keyPressEvent(QKeyEvent *event) {

    if (event->key() == Qt::Key_Escape) {
        emit signalAborted();
    }

}
