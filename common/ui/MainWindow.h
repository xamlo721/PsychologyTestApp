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
        void syncUserList(QList<UserAccount> users);

    public slots:
        void onTestComplete();
        void onTestReady();
        void displayLiriResult(LiriResult result);
        void displayTorstonResult();

    signals:
        void signalTestStarted();

        void signalAuthUser(UserAccount user);
        void signalAddUser(QString user);
        void signalEditUser(UserAccount user);
        void signalDeleteUser(UserAccount user);

    protected:
        virtual void keyPressEvent(QKeyEvent *event) override;

    private:

    private slots:
        void onTestStarted();

        void onAuthUser(UserAccount user);
        void onAddUser(QString user);
        void onEditUser(UserAccount user);
        void onDeleteUser(UserAccount user);

};


#endif // MAINWINDOW_H
