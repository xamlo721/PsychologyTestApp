#ifndef USERRESULTTORSTONWIDGET_H
#define USERRESULTTORSTONWIDGET_H

#include <QWidget>

namespace Ui {
    class UserResultTorstonWidget;
}

class UserResultTorstonWidget : public QWidget {

    Q_OBJECT

    public:
        explicit UserResultTorstonWidget(QWidget *parent = nullptr);
        ~UserResultTorstonWidget();

    private:
        Ui::UserResultTorstonWidget *ui;
};

#endif // USERRESULTTORSTONWIDGET_H
