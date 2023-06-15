#ifndef MAINTESTWIDGET_H
#define MAINTESTWIDGET_H

#include <QWidget>

#include "ui_MainTestWidget.h"

#include "common/items/EnumTestType.h"
#include "common/items/EnumTorsonResult.h"

namespace Ui {
    class MainTestWidget;
}

class MainTestWidget : public QWidget {

    Q_OBJECT

    public:
        explicit MainTestWidget(QWidget *parent = nullptr);
        ~MainTestWidget();
        void showResult(EnumTorsonResult result);

    public slots:
        void onMainMenuLiriTestButtonClicked();
        void onMainMenuTorsonTestButtonClicked();

        void onInfoLiriTestButtonClicked();
        void onInfoTorsonTestButtonClicked();

        void onTestAborted();
        void onHelpOpened();

    signals:
        void signalSelectTest(EnumTestType testType);
        void signalTestStarted();
        void signalTestComplete();
        void signalTestAborted();

    public://FIXME
        Ui::MainTestWidget *ui;
        void onTestComplete();


    protected:
        virtual void keyPressEvent(QKeyEvent *event) override;


};

#endif // MAINTESTWIDGET_H
