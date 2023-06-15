#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "ui_MainWindow.h"
#include "common/items/LiriResult.h"

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
        void onTestComplete();
        void onTestReady(QString user);
        void displayLiriResult(LiriResult result);
        void displayTorstonResult();

    signals:
        void signalTestStarted(QString user);

    protected:
        virtual void keyPressEvent(QKeyEvent *event) override;

    private:
        QString activeUser;

    private slots:

        void onTestStarted();



};


#endif // MAINWINDOW_H
