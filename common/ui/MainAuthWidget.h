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

    public slots:
        void onRespButtonPressed();
        void onPsychoButtonPressed();
        void onExitButton();

    signals:
        void signalApplicationClose();

    private:
        Ui::MainAuthWidget *ui;

};

#endif // MAINAUTHWIDGET_H