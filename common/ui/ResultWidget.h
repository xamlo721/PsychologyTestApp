#ifndef RESULTWIDGET_H
#define RESULTWIDGET_H

#include <QWidget>

#include "ui_Result.h"

#include "qradar.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class Result;
}
QT_END_NAMESPACE
class ResultWidget : public QWidget {

    Q_OBJECT

    public:
        explicit ResultWidget(QWidget *parent = nullptr);

        void displayRadar(int st1, int st2,int st3,int st4,int st5,int st6,int st7,int st8);
        void hideRadar();

    signals:

    public:
        Ui::Result *uiResult;
        QRadarChart * w;
        QColor blue = QColor(66, 66, 255, 128);
        QColor yellow = QColor(255, 255, 255, 255);

};

#endif // RESULTWIDGET_H
