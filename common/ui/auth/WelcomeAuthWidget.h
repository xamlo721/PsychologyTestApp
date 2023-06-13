#ifndef WELCOMEAUTHWIDGET_H
#define WELCOMEAUTHWIDGET_H

#include <QWidget>

namespace Ui {
    class WelcomeAuthWidget;
}

class WelcomeAuthWidget : public QWidget {

    Q_OBJECT

    public:
        explicit WelcomeAuthWidget(QWidget *parent = nullptr);
        ~WelcomeAuthWidget();

    signals:
        void signalRespOpen();
        void signalPsychoOpen();
        void signalApplicationClose();


    private:
        Ui::WelcomeAuthWidget *ui;
};

#endif // WELCOMEAUTHWIDGET_H
