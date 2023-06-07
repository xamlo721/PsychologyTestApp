#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>

#include "ui_MainWindow.h"
#include "common/items/EnumTestType.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {

    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    public slots:
        void onMainMenuLiriTestButtonClicked();
        void onMainMenuTorsonTestButtonClicked();

        void onInfoLiriTestButtonClicked();
        void onInfoTorsonTestButtonClicked();

    signals:
        void signalSelectTest(EnumTestType testType);

    public://FIXME
        Ui::MainWindow *ui_window;

};


#endif // MAINWINDOW_H
