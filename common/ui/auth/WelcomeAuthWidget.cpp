#include "WelcomeAuthWidget.h"
#include "ui_WelcomeAuthWidget.h"

WelcomeAuthWidget::WelcomeAuthWidget(QWidget *parent) : QWidget(parent), ui(new Ui::WelcomeAuthWidget) {
    ui->setupUi(this);

    QObject::connect(this->ui->openRespond_pushButton, &QPushButton::clicked, this, &WelcomeAuthWidget::signalRespOpen);
    QObject::connect(this->ui->openPsycho_pushButton, &QPushButton::clicked, this, &WelcomeAuthWidget::signalPsychoOpen);
    QObject::connect(this->ui->exit_pushButton, &QPushButton::clicked, this, &WelcomeAuthWidget::signalApplicationClose);

}

WelcomeAuthWidget::~WelcomeAuthWidget() {
    delete ui;
}
