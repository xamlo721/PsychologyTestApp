#ifndef USERRESULTLIRIWIDGET_H
#define USERRESULTLIRIWIDGET_H

#include <QWidget>

namespace Ui {
    class UserResultLiriWidget;
}

class UserResultLiriWidget : public QWidget {

    Q_OBJECT

    public:
        explicit UserResultLiriWidget(QWidget *parent = nullptr);
        ~UserResultLiriWidget();

    private:
        Ui::UserResultLiriWidget *ui;
};

#endif // USERRESULTLIRIWIDGET_H
