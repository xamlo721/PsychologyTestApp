#include "TestMenuWidget.h"



TestMenuWidget::TestMenuWidget(QWidget *parent) : QWidget(parent), ui(new Ui::TestMenuWidget) {
    ui->setupUi(this);


}


TestMenuWidget::~TestMenuWidget() {
    delete ui;
}
