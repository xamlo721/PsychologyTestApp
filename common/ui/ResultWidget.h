#ifndef RESULTWIDGET_H
#define RESULTWIDGET_H

#include <QWidget>

#include "ui_Result.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class Result;
}
QT_END_NAMESPACE
class ResultWidget : public QWidget {

    Q_OBJECT

    public:
        explicit ResultWidget(QWidget *parent = nullptr);

    signals:

    public:
        Ui::Result *uiResult;

};

#endif // RESULTWIDGET_H
