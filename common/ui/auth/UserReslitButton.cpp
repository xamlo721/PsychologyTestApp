#include "UserReslitButton.h"
#include "ui_UserReslitButton.h"

UserReslitButton::UserReslitButton(LiriResult result, QWidget *parent) : QPushButton(parent), ui(new Ui::UserReslitButton) {
    ui->setupUi(this);
    this->testType = EnumTestType::Liri;
    this->liriResult = result;
    this->setText("Тест Лири №" + QString::number(result.resultID));
    QObject::connect(this, &QPushButton::clicked, this, &UserReslitButton::onClicked);

}


UserReslitButton::UserReslitButton(TorstonResult result, QWidget *parent) : QPushButton(parent), ui(new Ui::UserReslitButton) {
    ui->setupUi(this);
    this->testType = EnumTestType::Torston;
    this->torstonResult = result;
    this->setText("Тест Торстона №" + QString::number(result.resultID));
    QObject::connect(this, &QPushButton::clicked, this, &UserReslitButton::onClicked);

}

void UserReslitButton::onClicked() {

    if (this->testType == EnumTestType::Liri) {
        emit signalLiriResultClicked(this->liriResult);
    } else {
        emit signalTorstonResultClicked(this->torstonResult);
    }

}

UserReslitButton::~UserReslitButton() {
    delete ui;
}
