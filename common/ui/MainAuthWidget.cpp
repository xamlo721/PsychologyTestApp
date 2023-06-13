#include "MainAuthWidget.h"

MainAuthWidget::MainAuthWidget(QWidget *parent) : QWidget(parent),  ui(new Ui::MainAuthWidget) {
    ui->setupUi(this);

    QObject::connect(this->ui->welcomePage, &WelcomeAuthWidget::signalRespOpen, this, &MainAuthWidget::onRespButtonPressed);
    QObject::connect(this->ui->welcomePage, &WelcomeAuthWidget::signalPsychoOpen, this, &MainAuthWidget::onPsychoButtonPressed);
    QObject::connect(this->ui->welcomePage, &WelcomeAuthWidget::signalApplicationClose, this, &MainAuthWidget::onExitButton);

}

void MainAuthWidget::onRespButtonPressed() {
    this->ui->stackedWidget->setCurrentIndex(1);
}

void MainAuthWidget::onPsychoButtonPressed() {

}

void MainAuthWidget::onExitButton() {
    //emit signalApplicationClose();
}

MainAuthWidget::~MainAuthWidget() {
    delete ui;
}
