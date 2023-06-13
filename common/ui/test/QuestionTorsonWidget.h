#ifndef QUESTIONTORSONWIDGET_H
#define QUESTIONTORSONWIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <Qt>
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
        void signalAnswered(bool a1, bool a2, bool a3, bool a4 );
        void signalAborted();

    public:
        Ui::QuestionsTorston *uiQuestionsTorston;

    protected:
        virtual void keyPressEvent(QKeyEvent *event) override;

};

#endif // QUESTIONTORSONWIDGET_H
