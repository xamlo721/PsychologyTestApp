#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>

#include "ui_InstructionLiri.h"
#include "ui_InstructionTorston.h"
#include "ui_MainWindow.h"
#include "ui_QuestionsLiri.h"
#include "ui_QuestionsTorston.h"
#include "ui_Result.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
    class InstructionMain;
    class InstructionMain;
    class QuestionsLiri;
    class QuestionsTorston;
    class Result;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {

    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private:
        Ui::MainWindow *ui_window;
        Ui::InstructionLiriWidget *uiInstructionLiri;
        Ui::InstructionTorstonWidget *uiInstructionTorston;
        Ui::QuestionsLiri *uiQuestionsLiri;
        Ui::QuestionsTorston *uiQuestionsTorston;
        Ui::Result *uiResult;

};


#endif // MAINWINDOW_H
