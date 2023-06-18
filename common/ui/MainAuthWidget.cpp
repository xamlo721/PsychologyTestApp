#include "MainAuthWidget.h"
#include "common/ui/auth/EnumAvailableAuthWidgets.h"
#include "common/items/TorstonResult.h"
#include "common/items/LiriResult.h"
#include "common/ui/auth/PsychoDialog.h"

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

    QObject::connect(this->ui->psychoResults, &PsychoResultWidget::signalLiriResultClicked, this, &MainAuthWidget::onPsychoShowLiriResult);
    QObject::connect(this->ui->psychoResults, &PsychoResultWidget::signalTorstonResultClicked, this, &MainAuthWidget::onPsychoShowTorstonResult);
    QObject::connect(this->ui->psychoResults, &PsychoResultWidget::signalDeleteLiriResult, this, &MainAuthWidget::onDeleteLiriResult);
    QObject::connect(this->ui->psychoResults, &PsychoResultWidget::signalDeleteTorstonResult, this, &MainAuthWidget::onDeleteTorstonResult);
    QObject::connect(this->ui->psychoResults, &PsychoResultWidget::signalCancelButtonPressed, this, &MainAuthWidget::openWelcomePage);

    QObject::connect(this->ui->psychoResults, &PsychoResultWidget::signalPasswordChanged, this, &MainAuthWidget::onPasswordChanged);

    QObject::connect(this->ui->userResultLiri, &UserResultLiriWidget::signalCancel, this, &MainAuthWidget::openWelcomePage);
    QObject::connect(this->ui->userResultTorston, &UserResultTorstonWidget::signalCancel, this, &MainAuthWidget::openWelcomePage);


}
//=================================================================================================

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
//=================================================================================================

void MainAuthWidget::syncUserList(QList<UserAccount> users) {
    this->ui->authPage->displayUserAccounts(users);
    this->ui->psychoResults->displayUserAccounts(users);
}

void MainAuthWidget::syncResultsList(QMap <UserAccount, QPair<QList<LiriResult>, QList<TorstonResult>>> results) {
    this->ui->psychoResults->displayUserResults(results);
}

void MainAuthWidget::syncProtocols(QMap <UserAccount, QPair<QList<AnswerProtocol>, QList<AnswerProtocol>>> protocols) {
    this->ui->psychoResults->syncProtocols(protocols);
}

void MainAuthWidget::onPsychoShowLiriResult(LiriResult result) {
    this->ui->userResultLiri->showResult(result);
    this->openUserLiriResult();
}

void MainAuthWidget::onPsychoShowTorstonResult(TorstonResult result) {
    this->ui->userResultTorston->showResult(result);
    this->openTorstonResult();

}

void MainAuthWidget::onDeleteLiriResult(UserAccount account, LiriResult result) {
    emit signalDeleteLiriResult(account, result);

}
void MainAuthWidget::onDeleteTorstonResult(UserAccount account, TorstonResult result) {
    emit signalDeleteTorstonResult(account, result);
}


void MainAuthWidget::onAuthUser(UserAccount user) {
    emit signalAuthUser(user);
    this->openWelcomePage();
    emit signalReadyForTest();
}

void MainAuthWidget::onAddUser(QString user) {
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

    PsychoDialog * dialog = new PsychoDialog(psychoPassword);
    dialog->setModal(true);
    dialog->show();
    QObject::connect(dialog, &PsychoDialog::signalAuthPsycho, this, &MainAuthWidget::openPsychoPage);

}

void MainAuthWidget::onPasswordChanged(QString newPassword) {
    this->psychoPassword = newPassword;
}


void MainAuthWidget::onExitButton() {
    emit signalWindowClose();
}

MainAuthWidget::~MainAuthWidget() {
    delete ui;
}
