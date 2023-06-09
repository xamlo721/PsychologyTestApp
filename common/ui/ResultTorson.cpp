#include "ResultTorson.h"

ResultTorson::ResultTorson(QWidget *parent) : QWidget(parent),  ui(new Ui::ResultTorson) {
    ui->setupUi(this);

}

ResultTorson::~ResultTorson() {
    delete ui;
}
