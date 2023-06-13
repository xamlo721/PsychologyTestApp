#ifndef QUESTIONLIRIWIDGET_H
#define QUESTIONLIRIWIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <Qt>

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
        void signalAnswerd(bool answer);
        void signalAborted();

    public:
        Ui::QuestionsLiri *uiQuestionsLiri;
        void setQuestion(QString question);

    private slots:
        void onYesButtonClicked();
        void onNoButtonClicked();

    protected:
        virtual void keyPressEvent(QKeyEvent *event) override;

};

#endif // QUESTIONLIRIWIDGET_H
