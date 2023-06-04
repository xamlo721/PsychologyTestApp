#include "MainMenuWidget.h"

MainMenuWidget::MainMenuWidget(QWidget *parent) : QWidget(parent), ui(new Ui::MainMenuWidget) {
    ui->setupUi(this);
}

MainMenuWidget::~MainMenuWidget() {
    delete ui;
}
