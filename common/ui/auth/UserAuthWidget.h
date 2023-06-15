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
        QMap <QString, UserAccountPutton * > accounts;
        QString selectedAccount;

    public:
        explicit UserAuthWidget(QWidget *parent = nullptr);
        ~UserAuthWidget();


    public slots:
        void onAuthButtonPressed();
        void onAddButtonPressed();
        void onEditButtonPressed();
        void onRemoveButtonPressed();
        void onCancelButtonPressed();

    private slots:
        void onUserAccountClicked(QString account);
        void onNewUserAccont(QString account);
        void onEditUserAccont(QString account);

    signals:
        void signalAuthUser();
        void signalAddUser();
        void signalEditUser();
        void signalDeleteUser();
        void signalCancel();

    private:
        void clearAccountsList();
        void showUserAccounts(QList <QString> accounts);//TODO: Добавить лист
        void onSelectAccount();
        void onUnselectAccount();


};

#endif // USERAUTHWIDGET_H
