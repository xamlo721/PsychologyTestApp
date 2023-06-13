#include "MainAuthWidget.h"

MainAuthWidget::MainAuthWidget(QWidget *parent) : QWidget(parent),  ui(new Ui::MainAuthWidget) {
    ui->setupUi(this);

    QObject::connect(this->ui->openRespond_pushButton, &QPushButton::clicked, this, &MainAuthWidget::onRespButtonPressed);
    QObject::connect(this->ui->openPsycho_pushButton, &QPushButton::clicked, this, &MainAuthWidget::onPsychoButtonPressed);
    QObject::connect(this->ui->exit_pushButton, &QPushButton::clicked, this, &MainAuthWidget::onExitButton);

}


void MainAuthWidget::onRespButtonPressed() {

}

void MainAuthWidget::onPsychoButtonPressed() {

}

void MainAuthWidget::onExitButton() {
    emit signalApplicationClose();
}

MainAuthWidget::~MainAuthWidget() {
    delete ui;
}
