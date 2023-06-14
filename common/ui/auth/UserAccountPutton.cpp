#include "UserAccountPutton.h"
#include "ui_UserAccountPutton.h"

UserAccountPutton::UserAccountPutton(QString name, QPushButton *parent) : QPushButton(parent), ui(new Ui::UserAccountPutton) {
    ui->setupUi(this);
    this->setText(name);
    QObject::connect(this, &QPushButton::clicked, this, &UserAccountPutton::onButtonClicked);//TODO: Не туда коннектим

}

void UserAccountPutton::onButtonClicked() {
    emit signalSelected(this->text());
}

UserAccountPutton::~UserAccountPutton() {
    delete ui;
}
