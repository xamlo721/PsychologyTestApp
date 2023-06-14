#include "UserResultTorstonWidget.h"
#include "ui_UserResultTorstonWidget.h"

UserResultTorstonWidget::UserResultTorstonWidget(QWidget *parent) : QWidget(parent), ui(new Ui::UserResultTorstonWidget) {
    ui->setupUi(this);
}

UserResultTorstonWidget::~UserResultTorstonWidget() {
    delete ui;
}
