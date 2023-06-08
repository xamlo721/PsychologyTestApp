#include "ResultWidget.h"


ResultWidget::ResultWidget(QWidget *parent) : QWidget(parent), uiResult(new Ui::Result) {
    uiResult->setupUi(this);
    this->w = new QRadarChart(this->uiResult->SectionResult);
    w->setStyleSheet(
        "QRadarChart{"
        "background-color:transparent;"
        "}"
    );

    w->configAxisColor(Qt::red);

    w->configAreaColor(blue, yellow, Qt::red, Qt::red);

    w->setMinimumSize(480, 320);


    w->addStat("1", 0);
    w->addStat("2", 0);
    w->addStat("3", 0);
    w->addStat("4", 0);
    w->addStat("5", 0);
    w->addStat("6", 0);
    w->addStat("7", 0);
    w->addStat("8", 0);
}

void ResultWidget::displayRadar(int st1, int st2,int st3,int st4,int st5,int st6,int st7,int st8) {

    w->updateStat(0, st1);
    w->updateStat(1, st2);
    w->updateStat(2, st3);
    w->updateStat(3, st4);
    w->updateStat(4, st5);
    w->updateStat(5, st6);
    w->updateStat(6, st7);
    w->updateStat(7, st8);

    w->getRadialAxis()->hide();

    w->drawChart();

    w->getCenterSeries()->hide();

    //w->show();

    this->w->setVisible(true);

}

void ResultWidget::hideRadar() {
    this->w->setVisible(false);
}

