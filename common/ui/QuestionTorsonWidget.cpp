#include "QuestionTorsonWidget.h"

QuestionTorsonWidget::QuestionTorsonWidget(QWidget *parent) : QWidget(parent), uiQuestionsTorston(new Ui::QuestionsTorston) {
    uiQuestionsTorston->setupUi(this);

    QObject::connect(this->uiQuestionsTorston->pushButton_nextQuestion, &QPushButton::clicked, this, &QuestionTorsonWidget::onButtonAnswerClicked);
}

void QuestionTorsonWidget::onButtonAnswerClicked() {

    emit signalAnswered(this->uiQuestionsTorston->button1->isChecked(),
                        this->uiQuestionsTorston->button2->isChecked(),
                        this->uiQuestionsTorston->button3->isChecked(),
                        this->uiQuestionsTorston->button4->isChecked()
                        );
}
