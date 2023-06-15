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

        void openWelcomePage();
        void openUserAuthPage();
        void openPsychoPage();
        void openUserLiriResult();
        void openTorstonResult();

    public slots:
        void onUserAuth(QString user);
        void onRespButtonPressed();
        void onPsychoButtonPressed();
        void onExitButton();

    signals:
        void signalReadyForTest(QString user);
        void signalWindowClose();

    private:
        Ui::MainAuthWidget *ui;

};

#endif // MAINAUTHWIDGET_H
