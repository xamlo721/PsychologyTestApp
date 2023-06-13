#include "MainAuthWidget.h"

MainAuthWidget::MainAuthWidget(QWidget *parent) : QWidget(parent),  ui(new Ui::MainAuthWidget) {
    ui->setupUi(this);
}

MainAuthWidget::~MainAuthWidget() {
    delete ui;
}
