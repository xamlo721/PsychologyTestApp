#include "UserResultLiriWidget.h"
#include "ui_UserResultLiriWidget.h"

UserResultLiriWidget::UserResultLiriWidget(QWidget *parent) : QWidget(parent), ui(new Ui::UserResultLiriWidget) {
    ui->setupUi(this);
}

UserResultLiriWidget::~UserResultLiriWidget() {
    delete ui;
}
