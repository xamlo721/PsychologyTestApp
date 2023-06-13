#ifndef USERAUTHWIDGET_H
#define USERAUTHWIDGET_H

#include <QWidget>

#include "ui_UserAuthWidget.h"

namespace Ui {
    class UserAuthWidget;
}

class UserAuthWidget : public QWidget {

    Q_OBJECT

    public:
        explicit UserAuthWidget(QWidget *parent = nullptr);
        ~UserAuthWidget();

    public slots:
        void onAuthButtonPressed();
        void onAddButtonPressed();
        void onEditButtonPressed();
        void onRemoveButtonPressed();
        void onCancelButtonPressed();

    private:
        Ui::UserAuthWidget *ui;

};

#endif // USERAUTHWIDGET_H
