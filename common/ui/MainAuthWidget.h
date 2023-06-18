#ifndef MAINAUTHWIDGET_H
#define MAINAUTHWIDGET_H

#include <QWidget>

#include "ui_MainAuthWidget.h"
#include "common/items/AnswerProtocol.h"

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
        void syncUserList(QList<UserAccount> users);
        void syncResultsList(QMap <UserAccount, QPair<QList<LiriResult>, QList<TorstonResult>>> results);
        void syncProtocols(QMap <UserAccount, QPair<QList<AnswerProtocol>, QList<AnswerProtocol>>> protocols);

    public slots:
        void onRespButtonPressed();
        void onPsychoButtonPressed();


    signals:
        void signalAuthUser(UserAccount user);
        void signalAddUser(QString user);
        void signalEditUser(UserAccount user);
        void signalDeleteUser(UserAccount user);
        void signalDeleteLiriResult(UserAccount account, LiriResult result);
        void signalDeleteTorstonResult(UserAccount account, TorstonResult result);
        void signalReadyForTest();
        void signalWindowClose();

    private slots:
        void onPsychoShowLiriResult(LiriResult result);
        void onPsychoShowTorstonResult(TorstonResult result);
        void onDeleteLiriResult(UserAccount account, LiriResult result);
        void onDeleteTorstonResult(UserAccount account, TorstonResult result);

        void onPasswordChanged(QString newPassword);

        void onAuthUser(UserAccount user);
        void onAddUser(QString user);
        void onEditUser(UserAccount user);
        void onDeleteUser(UserAccount user);
        void onExitButton();

    private:
        Ui::MainAuthWidget *ui;
        QString psychoPassword = "Jessle"; //TODO: Унести в ядро

};

#endif // MAINAUTHWIDGET_H
