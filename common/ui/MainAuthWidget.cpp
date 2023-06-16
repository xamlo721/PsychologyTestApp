#include "MainAuthWidget.h"
#include "common/ui/auth/EnumAvailableAuthWidgets.h"

MainAuthWidget::MainAuthWidget(QWidget *parent) : QWidget(parent),  ui(new Ui::MainAuthWidget) {
    ui->setupUi(this);

    QObject::connect(this->ui->welcomePage, &WelcomeAuthWidget::signalRespOpen, this, &MainAuthWidget::onRespButtonPressed);
    QObject::connect(this->ui->welcomePage, &WelcomeAuthWidget::signalPsychoOpen, this, &MainAuthWidget::onPsychoButtonPressed);
    QObject::connect(this->ui->welcomePage, &WelcomeAuthWidget::signalApplicationClose, this, &MainAuthWidget::onExitButton);
    QObject::connect(this->ui->authPage, &UserAuthWidget::signalAuthUser, this, &MainAuthWidget::onAuthUser);
    QObject::connect(this->ui->authPage, &UserAuthWidget::signalAddUser, this, &MainAuthWidget::onAddUser);
    QObject::connect(this->ui->authPage, &UserAuthWidget::signalEditUser, this, &MainAuthWidget::onEditUser);
    QObject::connect(this->ui->authPage, &UserAuthWidget::signalDeleteUser, this, &MainAuthWidget::onDeleteUser);
    QObject::connect(this->ui->authPage, &UserAuthWidget::signalCancel, this, &MainAuthWidget::openWelcomePage);
    QObject::connect(this->ui->psychoResults, &PsychoResultWidget::signalCancelButtonPressed, this, &MainAuthWidget::openWelcomePage);

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

void MainAuthWidget::onAuthUser(UserAccount user) {
    emit signalAuthUser(user);
    this->openWelcomePage();
}
#include <QDebug>

void MainAuthWidget::onAddUser(QString user) {
    qDebug() << user;
    emit signalAddUser(user);

}

void MainAuthWidget::onEditUser(UserAccount user) {
    emit signalEditUser(user);

}

void MainAuthWidget::onDeleteUser(UserAccount user) {
    emit signalDeleteUser(user);

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
