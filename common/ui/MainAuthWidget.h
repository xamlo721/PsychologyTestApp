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
        void syncUserList(QList<UserAccount> users);

    public slots:
        void onRespButtonPressed();
        void onPsychoButtonPressed();


    signals:
        void signalAuthUser(UserAccount user);
        void signalAddUser(QString user);
        void signalEditUser(UserAccount user);
        void signalDeleteUser(UserAccount user);
        void signalReadyForTest();
        void signalWindowClose();

    private slots:
        void onAuthUser(UserAccount user);
        void onAddUser(QString user);
        void onEditUser(UserAccount user);
        void onDeleteUser(UserAccount user);
        void onExitButton();

    private:
        Ui::MainAuthWidget *ui;

};

#endif // MAINAUTHWIDGET_H
