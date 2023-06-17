#ifndef PSYCHORESULTWIDGET_H
#define PSYCHORESULTWIDGET_H

#include <QWidget>
#include <QMap>

#include "common/items/UserAccount.h"
#include "common/ui/auth/UserAccountPutton.h"

namespace Ui {
    class PsychoResultWidget;
}

class PsychoResultWidget : public QWidget {

    Q_OBJECT

    private:
        Ui::PsychoResultWidget *ui;
        QMap <UserAccount, UserAccountPutton * > accounts;
        UserAccount selectedAccount;
        bool hasSelectedAccount;

    public:
        explicit PsychoResultWidget(QWidget *parent = nullptr);
        ~PsychoResultWidget();

        void changeAccountName(UserAccount account);
        void displayNewAccount(UserAccount account);
        void displayUserAccounts(QList <UserAccount> accounts);
        void removeDisplayedAccount(UserAccount account);

    signals:
        void signalUserResultClicked(UserAccount account);
        void signalLiriResultClicked(UserAccount account);
        void signalTorstonResultClicked(UserAccount account);
        void signalEditUser(UserAccount account);
        void signalEditResult(UserAccount account);
        void signalDeleteUser(UserAccount account);
        void signalDeleteResult(UserAccount account);
        void signalCancelButtonPressed();

    private slots:

        void onUserAccountClicked(UserAccount account);
        void onEditUserAccount(UserAccount account);

        void onAuthButtonPressed();
        void onAddButtonPressed();
        void onEditButtonPressed();
        void onRemoveButtonPressed();
        void onCancelButtonPressed();

    private:
        void clearAccountsListWidgets();
        void onSelectAccount();
        void onUnselectAccount();
};

#endif // PSYCHORESULTWIDGET_H
