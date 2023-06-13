#ifndef MAINAUTHWIDGET_H
#define MAINAUTHWIDGET_H

#include <QWidget>

#include "ui_MainAuthWidget.h"

namespace Ui {
    class MainAuthWidget;
}

class MainAuthWidget : public QWidget {

    Q_OBJECT

    public:
        explicit MainAuthWidget(QWidget *parent = nullptr);
        ~MainAuthWidget();

    private:
        Ui::MainAuthWidget *ui;

};

#endif // MAINAUTHWIDGET_H
