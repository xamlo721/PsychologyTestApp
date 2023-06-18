#ifndef PSYCHODIALOG_H
#define PSYCHODIALOG_H

#include <QDialog>


namespace Ui {
    class UserDialog;
}

class PsychoDialog : public QDialog {

    Q_OBJECT

    public:
        explicit PsychoDialog(QWidget *parent = nullptr);
        ~PsychoDialog();

    public slots:
        void onOkButtonClicked();

    signals:
        void signalAuthPsycho();

    private:
        Ui::UserDialog *ui;
        QString truePassword = "Jessle";

};

#endif // PSYCHODIALOG_H
