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
    //Костыль
    this->uiResult->label->setText(QApplication::translate("Result", "<html><head/><body><p>1. \320\220\320\262\321\202\320\276\321\200\320\270\321\202\320\260\321\200\320\275\321\213\320\271</p><p>2. \320\255\320\263\320\276\320\270\321\201\321\202\320\270\321\207\320\275\321\213\320\271</p><p>3. \320\220\320\263\321\200\320\265\321\201\321\201\320\270\320\262\320\275\321\213\320\271</p><p>4. \320\237\320\276\320\264\320\276\320\267\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\271</p><p>5. \320\237\320\276\321\207\320\270\320\275\321\217\320\265\320\274\321\213\320\271</p><p>6. \320\227\320\260\320\262\320\270\321\201\320\270\320\274\321\213\320\271</p><p>7. \320\224\321\200\321\203\320\266\320\265\320\273\321\216\320\261\320\275\321\213\320\271</p><p>8. \320\220\320\273\321\214\321\202\321\200\321\203\320\270\321\201\321\202\320\270\321\207\320\265\321\201\320\272\320\270\320\271</p></body></html>", nullptr));

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

