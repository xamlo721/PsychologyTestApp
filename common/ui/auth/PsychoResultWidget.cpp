#include "PsychoResultWidget.h"
#include "ui_PsychoResultWidget.h"

PsychoResultWidget::PsychoResultWidget(QWidget *parent) :  QWidget(parent), ui(new Ui::PsychoResultWidget) {
    ui->setupUi(this);
}

PsychoResultWidget::~PsychoResultWidget() {
    delete ui;
}
