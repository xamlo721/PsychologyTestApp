#include "PsychoDialog.h"
#include "ui_UserDialog.h"

PsychoDialog::PsychoDialog(QString passwd, QWidget *parent): QDialog(parent), ui(new Ui::UserDialog) {
    ui->setupUi(this);
    this->truePassword = passwd;
    this->ui->label->setText("Введите пароль: ");
    QObject::connect(this->ui->buttonBox, &QDialogButtonBox::accepted, this, &PsychoDialog::onOkButtonClicked);

}


void PsychoDialog::onOkButtonClicked() {
    if (this->ui->lineEdit->text() == this->truePassword) {
        emit signalAuthPsycho();
    }

}

PsychoDialog::~PsychoDialog() {
    delete ui;
}
