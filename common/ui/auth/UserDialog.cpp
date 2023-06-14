#include "UserDialog.h"
#include "ui_UserDialog.h"

UserDialog::UserDialog(QWidget *parent) : QDialog(parent), ui(new Ui::UserDialog) {
    ui->setupUi(this);
    QObject::connect(this->ui->buttonBox, &QDialogButtonBox::accepted, this, &UserDialog::onOkButtonClicked);

}

void UserDialog::onOkButtonClicked() {
    emit signalOnAnswered(this->ui->lineEdit->text());
}


UserDialog::~UserDialog() {
    delete ui;
}
