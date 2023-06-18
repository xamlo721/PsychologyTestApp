#ifndef USERTESTPROTOCOL_H
#define USERTESTPROTOCOL_H

#include <QWidget>
#include "common/items/AnswerProtocol.h"


namespace Ui {
    class UserTestProtocol;
}


class UserTestProtocol : public QWidget {

    Q_OBJECT

    public:
        explicit UserTestProtocol(QWidget *parent = nullptr);
        ~UserTestProtocol();


        void showProtocol(AnswerProtocol protocol);

    signals:
        void signalCancel();



    private:
        Ui::UserTestProtocol *ui;
};

#endif // USERTESTPROTOCOL_H
