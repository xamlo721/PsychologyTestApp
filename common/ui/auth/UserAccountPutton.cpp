#include "UserAccountPutton.h"
#include "ui_UserAccountPutton.h"

UserAccountPutton::UserAccountPutton(UserAccount user, QPushButton *parent) : QPushButton(parent), ui(new Ui::UserAccountPutton) {
    ui->setupUi(this);
    this->setText(user.getName());
    QObject::connect(this, &QPushButton::clicked, this, &UserAccountPutton::onButtonClicked);//TODO: Не туда коннектим

}

void UserAccountPutton::onButtonClicked() {
    emit signalSelected(this->user);
}

UserAccountPutton::~UserAccountPutton() {
    delete ui;
}
