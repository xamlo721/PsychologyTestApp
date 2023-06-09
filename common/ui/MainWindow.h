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

        void showResult(QString result);

    public slots:
        void onMainMenuLiriTestButtonClicked();
        void onMainMenuTorsonTestButtonClicked();

        void onInfoLiriTestButtonClicked();
        void onInfoTorsonTestButtonClicked();

        void onTestAborted();

    signals:
        void signalSelectTest(EnumTestType testType);
        void signalTestStarted(EnumTestType testType);
        void signalTestComplete();
        void signalTestAborted();

    public://FIXME
        Ui::MainWindow *ui_window;

        void onTestComplete();

    public:
        virtual void keyPressEvent(QKeyEvent *event) override;


};


#endif // MAINWINDOW_H
