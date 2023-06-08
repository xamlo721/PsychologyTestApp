#include "MainWindow.h"
#include "common/ui/EnumAvailableWidgets.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui_window(new Ui::MainWindow) {
    ui_window->setupUi(this);

    QObject::connect(this->ui_window->mainMenu->ui->TestLiri, &QPushButton::clicked, this, &MainWindow::onMainMenuLiriTestButtonClicked);
    QObject::connect(this->ui_window->mainMenu->ui->TestTorston, &QPushButton::clicked, this, &MainWindow::onMainMenuTorsonTestButtonClicked);

    QObject::connect(this->ui_window->infoLiri->uiInstructionLiri->tothetest, &QPushButton::clicked, this, &MainWindow::onInfoLiriTestButtonClicked);
    QObject::connect(this->ui_window->infoTorson->uiInstructionTorston->tothetest, &QPushButton::clicked, this, &MainWindow::onInfoTorsonTestButtonClicked);

    QObject::connect(this->ui_window->questResult->uiResult->tothemain, &QPushButton::clicked, this, &MainWindow::onTestComplete);

}

void MainWindow::showResult(QString result) {
    this->ui_window->stackedWidget->setCurrentIndex(EnumAvailableWidgets::Result);
    this->ui_window->questResult->uiResult->label->setText(result);
}


void MainWindow::onMainMenuLiriTestButtonClicked() {
    emit signalSelectTest(EnumTestType::Liri);
    this->ui_window->stackedWidget->setCurrentIndex(EnumAvailableWidgets::InfoLiri);

}

void MainWindow::onMainMenuTorsonTestButtonClicked() {
    emit signalSelectTest(EnumTestType::Torston);
    //TODO:
    this->ui_window->stackedWidget->setCurrentIndex(EnumAvailableWidgets::InfoTorson);

}

void MainWindow::onInfoLiriTestButtonClicked() {
    emit signalTestStarted(EnumTestType::Liri);
    this->ui_window->stackedWidget->setCurrentIndex(EnumAvailableWidgets::QuestLiri);
}

void MainWindow::onInfoTorsonTestButtonClicked() {
    emit signalTestStarted(EnumTestType::Torston);
    this->ui_window->stackedWidget->setCurrentIndex(EnumAvailableWidgets::QuestTorson);

}

void MainWindow::onTestComplete() {
    emit signalTestComplete();
    this->ui_window->stackedWidget->setCurrentIndex(EnumAvailableWidgets::MainMenu);

}


MainWindow::~MainWindow() {
    delete ui_window;
}

