#ifndef USERACCOUNTPUTTON_H
#define USERACCOUNTPUTTON_H

#include <QPushButton>

namespace Ui {
    class UserAccountPutton;
}

class UserAccountPutton : public QPushButton {

    Q_OBJECT

    public:
        explicit UserAccountPutton(QString name, QPushButton *parent = nullptr);
        ~UserAccountPutton();

    signals:
        void signalSelected(QString user);

    private slots:
        void onButtonClicked();

    private:
        Ui::UserAccountPutton *ui;

};

#endif // USERACCOUNTPUTTON_H
