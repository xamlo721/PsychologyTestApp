#ifndef USERDIALOG_H
#define USERDIALOG_H

#include <QDialog>

namespace Ui {
    class UserDialog;
}

class UserDialog : public QDialog {

    Q_OBJECT

    public:
        explicit UserDialog(QWidget *parent = nullptr);
        ~UserDialog();

    public slots:
        void onOkButtonClicked();

    signals:
        void signalOnAnswered(QString name);

    private:
        Ui::UserDialog *ui;
};

#endif // USERDIALOG_H
