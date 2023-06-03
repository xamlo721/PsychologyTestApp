#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    ui_window(new Ui::MainWindow),
    uiInstructionLiri(new Ui::InstructionLiriWidget),
    uiInstructionTorston(new Ui::InstructionTorstonWidget),
    uiQuestionsLiri(new Ui::QuestionsLiri),
    uiQuestionsTorston(new Ui::QuestionsTorston),
    uiResult(new Ui::Result)
{

    ui_window->setupUi(this);
    uiInstructionLiri->setupUi(new QWidget());
    uiInstructionTorston->setupUi(new QWidget());
    uiQuestionsLiri->setupUi(new QWidget());
    uiQuestionsTorston->setupUi(new QWidget());
    uiResult->setupUi(new QWidget());



}


MainWindow::~MainWindow() {
    delete ui_window;
}

