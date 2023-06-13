#include "UserAuthWidget.h"

UserAuthWidget::UserAuthWidget(QWidget *parent) : QWidget(parent), ui(new Ui::UserAuthWidget) {
    ui->setupUi(this);
    QObject::connect(this->ui->auth_pushButton, &QPushButton::clicked, this, &UserAuthWidget::onAuthButtonPressed);
    QObject::connect(this->ui->add_pushButton, &QPushButton::clicked, this, &UserAuthWidget::onAddButtonPressed);
    QObject::connect(this->ui->edit_pushButton, &QPushButton::clicked, this, &UserAuthWidget::onEditButtonPressed);
    QObject::connect(this->ui->remove_pushButton, &QPushButton::clicked, this, &UserAuthWidget::onRemoveButtonPressed);
    QObject::connect(this->ui->cancel_pushButton, &QPushButton::clicked, this, &UserAuthWidget::onCancelButtonPressed);
}


void UserAuthWidget::showUserAccounts() {//TODO: Добавить лист

}

void UserAuthWidget::onAuthButtonPressed() {

}

void UserAuthWidget::onAddButtonPressed() {

}

void UserAuthWidget::onEditButtonPressed() {

}

void UserAuthWidget::onRemoveButtonPressed() {

}

void UserAuthWidget::onCancelButtonPressed() {
    emit signalCancel();
}

void UserAuthWidget::onUserAccountClicked() {

}

QPushButton * UserAuthWidget::findPressedAccount() {

}

void UserAuthWidget::clearAccountsList() {

}

UserAuthWidget::~UserAuthWidget() {
    delete ui;
}
