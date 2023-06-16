#ifndef USERACCOUNTPUTTON_H
#define USERACCOUNTPUTTON_H

#include <QPushButton>
#include "common/items/UserAccount.h"

namespace Ui {
    class UserAccountPutton;
}

class UserAccountPutton : public QPushButton {

    Q_OBJECT

    public:
        explicit UserAccountPutton(UserAccount name, QPushButton *parent = nullptr);
        ~UserAccountPutton();

    signals:
        void signalSelected(UserAccount user);

    private slots:
        void onButtonClicked();

    private:
        Ui::UserAccountPutton *ui;
        UserAccount user;

};

#endif // USERACCOUNTPUTTON_H
