#ifndef QUESTIONLIRIWIDGET_H
#define QUESTIONLIRIWIDGET_H

#include <QWidget>

#include "ui_QuestionsLiri.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class QuestionsLiri;
}

QT_END_NAMESPACE
class QuestionLiriWidget : public QWidget {

    Q_OBJECT

    public:
        explicit QuestionLiriWidget(QWidget *parent = nullptr);

    signals:

    public:

        Ui::QuestionsLiri *uiQuestionsLiri;

};

#endif // QUESTIONLIRIWIDGET_H
