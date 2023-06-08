#ifndef QUESTIONTORSONWIDGET_H
#define QUESTIONTORSONWIDGET_H

#include <QWidget>

#include "ui_QuestionsTorston.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class QuestionsTorston;
}
QT_END_NAMESPACE

class QuestionTorsonWidget : public QWidget {

    Q_OBJECT

    public:
        explicit QuestionTorsonWidget(QWidget *parent = nullptr);

    private slots:
        void onButtonAnswerClicked();

    signals:
        void signalAnswered(bool a1, bool a2, bool a3, bool a4 ,bool a5);

    public:
        Ui::QuestionsTorston *uiQuestionsTorston;

};

#endif // QUESTIONTORSONWIDGET_H
