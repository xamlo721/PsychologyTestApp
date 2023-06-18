#ifndef CHANGEPASSWORDDIALOG_H
#define CHANGEPASSWORDDIALOG_H

#include <QDialog>

namespace Ui {
    class UserDialog;
}

class ChangePasswordDialog : public QDialog {

    Q_OBJECT

    public:
        explicit ChangePasswordDialog(QWidget *parent = nullptr);
        ~ChangePasswordDialog();

    public slots:
        void onOkButtonClicked();

    signals:
        void signalPasswordChanged(QString newPassword);

    private:
        Ui::UserDialog *ui;

};

#endif // CHANGEPASSWORDDIALOG_H
