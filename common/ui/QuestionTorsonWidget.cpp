#include "QuestionTorsonWidget.h"

QuestionTorsonWidget::QuestionTorsonWidget(QWidget *parent) : QWidget(parent), uiQuestionsTorston(new Ui::QuestionsTorston) {
    uiQuestionsTorston->setupUi(this);

    QObject::connect(this->uiQuestionsTorston->pushButton_nextQuestion, &QPushButton::clicked, this, &QuestionTorsonWidget::onButtonAnswerClicked);
}

void QuestionTorsonWidget::onButtonAnswerClicked() {
    QList<int> variants;

    if (this->uiQuestionsTorston->button1->isChecked()) {
        variants.append(1);
    }

    if (this->uiQuestionsTorston->button2->isChecked()) {
        variants.append(2);
    }

    if (this->uiQuestionsTorston->button3->isChecked()) {
        variants.append(3);
    }

    if (this->uiQuestionsTorston->button4->isChecked()) {
        variants.append(4);
    }

    if (this->uiQuestionsTorston->button5->isChecked()) {
        variants.append(5);
    }

    emit signalAnswered(variants);
}
