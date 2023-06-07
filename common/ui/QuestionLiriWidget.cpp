#include "QuestionLiriWidget.h"

QuestionLiriWidget::QuestionLiriWidget(QWidget *parent) : QWidget(parent), uiQuestionsLiri(new Ui::QuestionsLiri) {
    uiQuestionsLiri->setupUi(this);
    QObject::connect(this->uiQuestionsLiri->NO, &QPushButton::clicked, this, &QuestionLiriWidget::onNoButtonClicked);
    QObject::connect(this->uiQuestionsLiri->YES, &QPushButton::clicked, this, &QuestionLiriWidget::onYesButtonClicked);
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
