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

    signals:

    public:
        Ui::QuestionsTorston *uiQuestionsTorston;

};

#endif // QUESTIONTORSONWIDGET_H
