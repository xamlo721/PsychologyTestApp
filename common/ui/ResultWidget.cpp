#include "ResultWidget.h"


ResultWidget::ResultWidget(QWidget *parent) : QWidget(parent), uiResult(new Ui::Result) {
    uiResult->setupUi(this);

}

void ResultWidget::displayRadar(int st1, int st2,int st3,int st4,int st5,int st6,int st7,int st8) {
    this->w = new QRadarChart(this->uiResult->SectionResult);
    w->setStyleSheet(
        "QRadarChart{"
        "background-color:transparent;"
        "}"
    );

    w->configAxisColor(Qt::red);

    w->configAreaColor(blue, yellow, Qt::red, Qt::red);

    w->setMinimumSize(480, 320); //Поправь пожалуйта как тебе надо

    w->addStat("1", st1);
    w->addStat("2", st2);
    w->addStat("3", st3);
    w->addStat("4", st4);
    w->addStat("5", st5);
    w->addStat("6", st6);
    w->addStat("7", st7);
    w->addStat("8", st8);

    w->getRadialAxis()->hide();

    w->drawChart();

    w->getCenterSeries()->hide();

    this->w->setVisible(true);

}

void ResultWidget::hideRadar() {
    if (this->w != 0) {
        this->w->setVisible(false);
        this->w->close();
        this->w->hide();
        delete this->w;
        this->w = 0;
    }
}

