#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "ui_MainWindow.h"

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

    public://FIXME
        Ui::MainWindow *ui;

        void onHelpOpened();

    public slots:
        void onTestReady();

    protected:
        virtual void keyPressEvent(QKeyEvent *event) override;

};


#endif // MAINWINDOW_H
