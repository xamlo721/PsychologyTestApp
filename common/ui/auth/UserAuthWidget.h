#ifndef USERAUTHWIDGET_H
#define USERAUTHWIDGET_H

#include <QWidget>

#include "ui_UserAuthWidget.h"
#include "common/ui/auth/UserAccountPutton.h"
#include <QMap>

namespace Ui {
    class UserAuthWidget;
}

class UserAuthWidget : public QWidget {

    Q_OBJECT

    private:
        Ui::UserAuthWidget *ui;

    public:
        explicit UserAuthWidget(QWidget *parent = nullptr);
        ~UserAuthWidget();

        void showUserAccounts();//TODO: Добавить лист

    public slots:
        void onAuthButtonPressed();
        void onAddButtonPressed();
        void onEditButtonPressed();
        void onRemoveButtonPressed();
        void onCancelButtonPressed();

    private slots:
        void onUserAccountClicked(QString account);
        void onNewUserAccont(QString account);

    signals:
        void signalAuthUser();
        void signalAddUser();
        void signalEditUser();
        void signalDeleteUser();
        void signalCancel();

    private:
        QPushButton * findPressedAccount();
        void clearAccountsList();
        QMap <QString, UserAccountPutton * > accounts;
        QString selectedAccount;

};

#endif // USERAUTHWIDGET_H
