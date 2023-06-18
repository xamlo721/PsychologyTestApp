#include "UserResultLiriWidget.h"
#include "ui_UserResultLiriWidget.h"

UserResultLiriWidget::UserResultLiriWidget(QWidget *parent) : QWidget(parent), ui(new Ui::UserResultLiriWidget) {
    ui->setupUi(this);


    QObject::connect(this->ui->tothemain, &QPushButton::clicked, this, &UserResultLiriWidget::signalCancel);
}

void UserResultLiriWidget::showResult(LiriResult result) {
    this->displayRadar(result.st1, result.st2, result.st3, result.st4,
                       result.st5, result.st6, result.st7, result.st8);
    this->ui->username->setText(result.user.getName());
}


void UserResultLiriWidget::displayRadar(int st1, int st2,int st3,int st4,int st5,int st6,int st7,int st8) {
    this->hideRadar();

    ui->radar = new QRadarChart(this->ui->SectionResult);
    ui->radar->setObjectName(QString::fromUtf8("radar"));
    ui->radar->setGeometry(QRect(40, 10, 360, 360));
    ui->radar->setStyleSheet(
        "QRadarChart{"
        "background-color:transparent;"
        "}"
    );

    ui->radar->configAxisColor(Qt::red);

    ui->radar->configAreaColor(blue, yellow, Qt::red, Qt::red);

    ui->radar->setMinimumSize(480, 320); //Поправь пожалуйта как тебе надо

    ui->radar->addStat("1", st1);
    ui->radar->addStat("2", st2);
    ui->radar->addStat("3", st3);
    ui->radar->addStat("4", st4);
    ui->radar->addStat("5", st5);
    ui->radar->addStat("6", st6);
    ui->radar->addStat("7", st7);
    ui->radar->addStat("8", st8);

    ui->radar->getRadialAxis()->hide();

    ui->radar->drawChart();

    ui->radar->getCenterSeries()->hide();

    ui->radar->setVisible(true);
    //Костыль
//    this->uiResult->label->setText(QApplication::translate("Result", "<html><head/><body><p>1. \320\220\320\262\321\202\320\276\321\200\320\270\321\202\320\260\321\200\320\275\321\213\320\271</p><p>2. \320\255\320\263\320\276\320\270\321\201\321\202\320\270\321\207\320\275\321\213\320\271</p><p>3. \320\220\320\263\321\200\320\265\321\201\321\201\320\270\320\262\320\275\321\213\320\271</p><p>4. \320\237\320\276\320\264\320\276\320\267\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\271</p><p>5. \320\237\320\276\321\207\320\270\320\275\321\217\320\265\320\274\321\213\320\271</p><p>6. \320\227\320\260\320\262\320\270\321\201\320\270\320\274\321\213\320\271</p><p>7. \320\224\321\200\321\203\320\266\320\265\320\273\321\216\320\261\320\275\321\213\320\271</p><p>8. \320\220\320\273\321\214\321\202\321\200\321\203\320\270\321\201\321\202\320\270\321\207\320\265\321\201\320\272\320\270\320\271</p></body></html>", nullptr));

}

void UserResultLiriWidget::hideRadar() {
    if (ui->radar != 0) {
        ui->radar->setVisible(false);
        ui->radar->close();
        ui->radar->hide();
        delete ui->radar;
        ui->radar = 0;
    }
}

UserResultLiriWidget::~UserResultLiriWidget() {
    delete ui;
}
