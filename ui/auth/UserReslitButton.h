#ifndef USERRESLITBUTTON_H
#define USERRESLITBUTTON_H

#include <QPushButton>
#include <common/items/EnumTestType.h>
#include "common/items/LiriResult.h"
#include "common/items/TorstonResult.h"

namespace Ui {
    class UserReslitButton;
}

class UserReslitButton : public QPushButton {

    Q_OBJECT

    private:
        Ui::UserReslitButton *ui;
        EnumTestType testType;
        LiriResult liriResult;
        TorstonResult torstonResult;

    public:
        explicit UserReslitButton(LiriResult result, QWidget *parent = nullptr);
        explicit UserReslitButton(TorstonResult result, QWidget *parent = nullptr);

    signals:
        void signalLiriResultClicked(LiriResult result);
        void signalTorstonResultClicked(TorstonResult result);

    private slots:
        void onClicked();

    public:
        ~UserReslitButton();


};

#endif // USERRESLITBUTTON_H
