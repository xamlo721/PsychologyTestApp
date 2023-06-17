#ifndef USERAUTHWIDGET_H
#define USERAUTHWIDGET_H

#include <QWidget>

#include "ui_UserAuthWidget.h"
#include "common/ui/auth/UserAccountPutton.h"
#include "common/items/UserAccount.h"
#include <QMap>

namespace Ui {
    class UserAuthWidget;
}

class UserAuthWidget : public QWidget {

    Q_OBJECT

    private:
        Ui::UserAuthWidget *ui;
        QMap <UserAccount, UserAccountPutton * > accounts;
        UserAccount selectedAccount;
        bool hasSelectedAccount;

    public:
        explicit UserAuthWidget(QWidget *parent = nullptr);
        ~UserAuthWidget();

        void changeAccountName(UserAccount account);
        void displayNewAccount(UserAccount account);
        void displayUserAccounts(QList <UserAccount> accounts);
        void removeDisplayedAccount(UserAccount account);

    private slots:
        void onUserAccountClicked(UserAccount account);
        void onEditUserAccount(UserAccount account);

        void onAuthButtonPressed();
        void onAddButtonPressed();
        void onEditButtonPressed();
        void onRemoveButtonPressed();
        void onCancelButtonPressed();

    signals:
        void signalAuthUser(UserAccount account);
        void signalAddUser(QString account);
        void signalEditUser(UserAccount account);
        void signalDeleteUser(UserAccount account);
        void signalCancel();

    private:
        void clearAccountsListWidgets();
        void onSelectAccount();
        void onUnselectAccount();

};

#endif // USERAUTHWIDGET_H
