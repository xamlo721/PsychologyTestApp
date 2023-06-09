#include "ResultWidget.h"


ResultWidget::ResultWidget(QWidget *parent) : QWidget(parent), uiResult(new Ui::Result) {
    uiResult->setupUi(this);

}

void ResultWidget::displayRadar(int st1, int st2,int st3,int st4,int st5,int st6,int st7,int st8) {
    this->hideRadar();

    uiResult->radar = new QRadarChart(this->uiResult->SectionResult);
    uiResult->radar->setObjectName(QString::fromUtf8("radar"));
    uiResult->radar->setGeometry(QRect(40, 10, 360, 360));
    uiResult->radar->setStyleSheet(
        "QRadarChart{"
        "background-color:transparent;"
        "}"
    );

    uiResult->radar->configAxisColor(Qt::red);

    uiResult->radar->configAreaColor(blue, yellow, Qt::red, Qt::red);

    uiResult->radar->setMinimumSize(480, 320); //Поправь пожалуйта как тебе надо

    uiResult->radar->addStat("1", st1);
    uiResult->radar->addStat("2", st2);
    uiResult->radar->addStat("3", st3);
    uiResult->radar->addStat("4", st4);
    uiResult->radar->addStat("5", st5);
    uiResult->radar->addStat("6", st6);
    uiResult->radar->addStat("7", st7);
    uiResult->radar->addStat("8", st8);

    uiResult->radar->getRadialAxis()->hide();

    uiResult->radar->drawChart();

    uiResult->radar->getCenterSeries()->hide();

    uiResult->radar->setVisible(true);
    //Костыль
//    this->uiResult->label->setText(QApplication::translate("Result", "<html><head/><body><p>1. \320\220\320\262\321\202\320\276\321\200\320\270\321\202\320\260\321\200\320\275\321\213\320\271</p><p>2. \320\255\320\263\320\276\320\270\321\201\321\202\320\270\321\207\320\275\321\213\320\271</p><p>3. \320\220\320\263\321\200\320\265\321\201\321\201\320\270\320\262\320\275\321\213\320\271</p><p>4. \320\237\320\276\320\264\320\276\320\267\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\271</p><p>5. \320\237\320\276\321\207\320\270\320\275\321\217\320\265\320\274\321\213\320\271</p><p>6. \320\227\320\260\320\262\320\270\321\201\320\270\320\274\321\213\320\271</p><p>7. \320\224\321\200\321\203\320\266\320\265\320\273\321\216\320\261\320\275\321\213\320\271</p><p>8. \320\220\320\273\321\214\321\202\321\200\321\203\320\270\321\201\321\202\320\270\321\207\320\265\321\201\320\272\320\270\320\271</p></body></html>", nullptr));

}

void ResultWidget::hideRadar() {
    if (uiResult->radar != 0) {
        uiResult->radar->setVisible(false);
        uiResult->radar->close();
        uiResult->radar->hide();
        delete uiResult->radar;
        uiResult->radar = 0;
    }
}

