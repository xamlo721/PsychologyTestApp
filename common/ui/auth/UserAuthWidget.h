#ifndef USERAUTHWIDGET_H
#define USERAUTHWIDGET_H

#include <QWidget>

#include "ui_UserAuthWidget.h"

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
        void onUserAccountClicked();

    signals:
        void signalAuthUser();
        void signalAddUser();
        void signalEditUser();
        void signalDeleteUser();
        void signalCancel();

    private:
        QPushButton * findPressedAccount();
        void clearAccountsList();

};

#endif // USERAUTHWIDGET_H
