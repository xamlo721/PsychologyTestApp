#include "MainWindow.h"
#include "common/ui/EnumAvailableWidgets.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui_window(new Ui::MainWindow) {
    ui_window->setupUi(this);

    QObject::connect(this->ui_window->mainMenu->ui->TestLiri, &QPushButton::clicked, this, &MainWindow::onMainMenuLiriTestButtonClicked);
    QObject::connect(this->ui_window->mainMenu->ui->TestTorston, &QPushButton::clicked, this, &MainWindow::onMainMenuTorsonTestButtonClicked);

    QObject::connect(this->ui_window->infoLiri->uiInstructionLiri->tothetest, &QPushButton::clicked, this, &MainWindow::onInfoLiriTestButtonClicked);
    QObject::connect(this->ui_window->infoTorson->uiInstructionTorston->tothetest, &QPushButton::clicked, this, &MainWindow::onInfoTorsonTestButtonClicked);

}

void MainWindow::onMainMenuLiriTestButtonClicked() {
    this->ui_window->stackedWidget->setCurrentIndex(EnumAvailableWidgets::InfoLiri);
}

void MainWindow::onMainMenuTorsonTestButtonClicked() {
    //TODO:
}

void MainWindow::onInfoLiriTestButtonClicked() {
    this->ui_window->stackedWidget->setCurrentIndex(EnumAvailableWidgets::QuestLiri);
}

void MainWindow::onInfoTorsonTestButtonClicked() {

}


MainWindow::~MainWindow() {
    delete ui_window;
}

