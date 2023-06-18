#ifndef USERRESULTLIRIWIDGET_H
#define USERRESULTLIRIWIDGET_H

#include <QWidget>
#include "common/items/LiriResult.h"

namespace Ui {
    class UserResultLiriWidget;
}

class UserResultLiriWidget : public QWidget {

    Q_OBJECT

    public:
        explicit UserResultLiriWidget(QWidget *parent = nullptr);
        ~UserResultLiriWidget();

        void showResult(LiriResult result);

    signals:
        void signalCancel();

    private:
        void displayRadar(int st1, int st2,int st3,int st4,int st5,int st6,int st7,int st8);
        void hideRadar();
        Ui::UserResultLiriWidget *ui;
        QColor blue = QColor(150, 255, 128, 128);
        QColor yellow = QColor(255, 255, 255, 255);
};

#endif // USERRESULTLIRIWIDGET_H
