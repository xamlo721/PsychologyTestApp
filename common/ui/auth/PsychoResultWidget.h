#ifndef PSYCHORESULTWIDGET_H
#define PSYCHORESULTWIDGET_H

#include <QWidget>

namespace Ui {
class PsychoResultWidget;
}

class PsychoResultWidget : public QWidget {

    Q_OBJECT

    public:
        explicit PsychoResultWidget(QWidget *parent = nullptr);
        ~PsychoResultWidget();

    signals:
        void signalCancelButtonPressed();

    private slots:
            void onCancelButtonPressed();

    private:
        Ui::PsychoResultWidget *ui;
};

#endif // PSYCHORESULTWIDGET_H
