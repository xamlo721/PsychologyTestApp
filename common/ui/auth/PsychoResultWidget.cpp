#include "PsychoResultWidget.h"
#include "ui_PsychoResultWidget.h"

PsychoResultWidget::PsychoResultWidget(QWidget *parent) :  QWidget(parent), ui(new Ui::PsychoResultWidget) {
    ui->setupUi(this);
    QObject::connect(this->ui->cancel_pushButton, &QPushButton::clicked, this, &PsychoResultWidget::onCancelButtonPressed);

}

void PsychoResultWidget::onCancelButtonPressed() {

    //TODO: какие-то действия по закрытию окон
    emit signalCancelButtonPressed();
}

PsychoResultWidget::~PsychoResultWidget() {
    delete ui;
}
