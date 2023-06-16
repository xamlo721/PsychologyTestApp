#include "UserDialog.h"
#include "ui_UserDialog.h"

UserDialog::UserDialog(UserAccount user, QWidget *parent) : QDialog(parent), ui(new Ui::UserDialog) {
    ui->setupUi(this);
    this->displayedAccount = user;
    this->ui->lineEdit->setText(user.getName());
    QObject::connect(this->ui->buttonBox, &QDialogButtonBox::accepted, this, &UserDialog::onOkButtonClicked);

}

UserDialog::UserDialog(QWidget *parent): QDialog(parent), ui(new Ui::UserDialog) {
    ui->setupUi(this);
    this->ui->lineEdit->setText("Введите имя пользователя");
    QObject::connect(this->ui->buttonBox, &QDialogButtonBox::accepted, this, &UserDialog::onOkButtonClicked);

}


void UserDialog::changeDispalayedUser(UserAccount user) {
    this->ui->lineEdit->setText(user.getName());
    this->displayedAccount = user;
}


void UserDialog::onOkButtonClicked() {
    if (this->hasAccount) {
        this->displayedAccount.changeUserName(this->ui->lineEdit->text());
        emit signalEditUserName(this->displayedAccount);
    } else {
        emit signalCreateNewUser(this->ui->lineEdit->text());
    }

}

UserDialog::~UserDialog() {
    delete ui;
}
