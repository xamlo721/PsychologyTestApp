#ifndef USERRESULTTORSTONWIDGET_H
#define USERRESULTTORSTONWIDGET_H

#include <QWidget>
#include "common/items/TorstonResult.h"

namespace Ui {
    class UserResultTorstonWidget;
}

class UserResultTorstonWidget : public QWidget {

    Q_OBJECT

    public:
        explicit UserResultTorstonWidget(QWidget *parent = nullptr);
        ~UserResultTorstonWidget();

        void showResult(TorstonResult result);

    signals:
        void signalCancel();

    private:
        Ui::UserResultTorstonWidget *ui;
};

#endif // USERRESULTTORSTONWIDGET_H
