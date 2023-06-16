#ifndef USERDIALOG_H
#define USERDIALOG_H

#include <QDialog>

#include "common/items/UserAccount.h"

namespace Ui {
    class UserDialog;
}

class UserDialog : public QDialog {

    Q_OBJECT

    public:
        explicit UserDialog(UserAccount user, QWidget *parent = nullptr);
        explicit UserDialog(QWidget *parent = nullptr);
        ~UserDialog();

        void changeDispalayedUser(UserAccount user);

    public slots:
        void onOkButtonClicked();

    signals:
        void signalCreateNewUser(QString userName);
        void signalEditUserName(UserAccount user);

    private:
        Ui::UserDialog *ui;
        UserAccount displayedAccount;
        bool hasAccount;
};

#endif // USERDIALOG_H
