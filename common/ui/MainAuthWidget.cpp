#include "MainAuthWidget.h"
#include "common/ui/auth/EnumAvailableAuthWidgets.h"

MainAuthWidget::MainAuthWidget(QWidget *parent) : QWidget(parent),  ui(new Ui::MainAuthWidget) {
    ui->setupUi(this);

    QObject::connect(this->ui->welcomePage, &WelcomeAuthWidget::signalRespOpen, this, &MainAuthWidget::onRespButtonPressed);
    QObject::connect(this->ui->welcomePage, &WelcomeAuthWidget::signalPsychoOpen, this, &MainAuthWidget::onPsychoButtonPressed);
    QObject::connect(this->ui->welcomePage, &WelcomeAuthWidget::signalApplicationClose, this, &MainAuthWidget::onExitButton);
    QObject::connect(this->ui->authPage, &UserAuthWidget::signalAuthUser, this, &MainAuthWidget::onUserAuth);

}

void MainAuthWidget::openWelcomePage() {
    this->ui->stackedWidget->setCurrentIndex(EnumAvailableAuthWidgets::Welcome);
}

void MainAuthWidget::openUserAuthPage() {
    this->ui->stackedWidget->setCurrentIndex(EnumAvailableAuthWidgets::UserAuth);
}

void MainAuthWidget::openPsychoPage() {
    this->ui->stackedWidget->setCurrentIndex(EnumAvailableAuthWidgets::PsychoAuth);
}

void MainAuthWidget::openUserLiriResult() {
    this->ui->stackedWidget->setCurrentIndex(EnumAvailableAuthWidgets::UserResultLiri);
}

void MainAuthWidget::openTorstonResult() {
    this->ui->stackedWidget->setCurrentIndex(EnumAvailableAuthWidgets::UserResultTorston);
}

void MainAuthWidget::onUserAuth() {
    //TODO: Запомнить что за юзер тестируется
    emit signalReadyForTest();
}

void MainAuthWidget::onRespButtonPressed() {
    this->openUserAuthPage();
}

void MainAuthWidget::onPsychoButtonPressed() {
    this->openPsychoPage();
}

void MainAuthWidget::onExitButton() {
    emit signalWindowClose();
}

MainAuthWidget::~MainAuthWidget() {
    delete ui;
}
