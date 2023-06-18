#ifndef PSYCHODIALOG_H
#define PSYCHODIALOG_H

#include <QDialog>


namespace Ui {
    class UserDialog;
}

class PsychoDialog : public QDialog {

    Q_OBJECT

    public:
        explicit PsychoDialog(QString passwd = "Jessle", QWidget *parent = nullptr);
        ~PsychoDialog();

    public slots:
        void onOkButtonClicked();

    signals:
        void signalAuthPsycho();

    private:
        Ui::UserDialog *ui;
        QString truePassword ;

};

#endif // PSYCHODIALOG_H
