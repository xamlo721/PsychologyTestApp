#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "ui_MainWindow.h"
#include "common/items/LiriResult.h"
#include "common/items/TorstonResult.h"
#include "common/items/Question.h"

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

        void displayLiriResult(LiriResult result);
        void displayTorstonResult(TorstonResult result);
        void updateProgressBar(float completePercent);
        void syncUserList(QList<UserAccount> users);
        void syncResultsList(QMap <UserAccount, QPair<QList<LiriResult>, QList<TorstonResult>>> results);
        void changeLiriQuestion(Question q);
        void changeTorstonQuestion(Question q);

    private://FIXME
        Ui::MainWindow *ui;
        void onHelpOpened();


    public slots:
        void onTestComplete();
        void onTestReady();


    signals:

        void signalAuthUser(UserAccount user);
        void signalAddUser(QString user);
        void signalEditUser(UserAccount user);
        void signalDeleteUser(UserAccount user);
        void signalDeleteLiriResult(UserAccount account, LiriResult result);
        void signalDeleteTorstonResult(UserAccount account, TorstonResult result);

        void signalSelectTest(EnumTestType testType);
        void signalTestStarted();
        void signalTestComplete();
        void signalTestAborted();
        void signalLiriAnswered(bool answer);
        void signalTorstonAnswered(bool a1, bool a2, bool a3, bool a4 );

    protected:
        virtual void keyPressEvent(QKeyEvent *event) override;

    private:

    private slots:
        void onTestStarted();

        void onAuthUser(UserAccount user);
        void onAddUser(QString user);
        void onEditUser(UserAccount user);
        void onDeleteUser(UserAccount user);
        void onDeleteLiriResult(UserAccount account, LiriResult result);
        void onDeleteTorstonResult(UserAccount account, TorstonResult result);


};


#endif // MAINWINDOW_H
