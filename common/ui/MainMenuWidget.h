#ifndef MAINMENUWIDGET_H
#define MAINMENUWIDGET_H

#include <QWidget>
#include "ui_MainMenuWidget.h"

namespace Ui {
    class MainMenuWidget;
}

class MainMenuWidget : public QWidget {
    Q_OBJECT

    public:
        explicit MainMenuWidget(QWidget *parent = nullptr);
        ~MainMenuWidget();

    public:
        Ui::MainMenuWidget *ui;
};

#endif // MAINMENUWIDGET_H
