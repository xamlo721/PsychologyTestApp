#ifndef MAINMENUWIDGET_H
#define MAINMENUWIDGET_H

#include <QWidget>
#include "ui_TestMenuWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class TestMenuWidget;
}
QT_END_NAMESPACE


class TestMenuWidget : public QWidget {

    Q_OBJECT

    public:
        explicit TestMenuWidget(QWidget *parent = nullptr);
        ~TestMenuWidget();

    public:
        Ui::TestMenuWidget *ui;

};

#endif // MAINMENUWIDGET_H
