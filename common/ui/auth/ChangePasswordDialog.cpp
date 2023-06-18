#include "ChangePasswordDialog.h"
#include "ui_UserDialog.h"

ChangePasswordDialog::ChangePasswordDialog(QWidget *parent): QDialog(parent), ui(new Ui::UserDialog) {
    ui->setupUi(this);
    this->ui->label->setText("Введите новый пароль: ");
    QObject::connect(this->ui->buttonBox, &QDialogButtonBox::accepted, this, &ChangePasswordDialog::onOkButtonClicked);

}


void ChangePasswordDialog::onOkButtonClicked() {
        emit signalPasswordChanged(this->ui->lineEdit->text());
}

ChangePasswordDialog::~ChangePasswordDialog() {
    delete ui;
}
