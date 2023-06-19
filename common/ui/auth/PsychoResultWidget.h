#ifndef PSYCHORESULTWIDGET_H
#define PSYCHORESULTWIDGET_H

#include <QWidget>
#include <QMap>

#include "common/items/UserAccount.h"
#include "common/items/TorstonResult.h"
#include "common/items/LiriResult.h"
#include "common/ui/auth/UserAccountPutton.h"
#include "common/ui/auth/UserReslitButton.h"
#include "common/items/AnswerProtocol.h"

#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>
#include <QTextEdit>
#include <QFileDialog>
#include <QFileInfo>
#include <QDebug>

namespace Ui {
    class PsychoResultWidget;
}

class PsychoResultWidget : public QWidget {

    Q_OBJECT

    private:
        Ui::PsychoResultWidget *ui;
        QMap <UserAccount, UserAccountPutton * > accounts;
        QMap <UserAccount, QList<UserReslitButton * >> displayesResults;
        QMap <UserAccount, QPair<QList<LiriResult>, QList<TorstonResult>>> results;
        QMap <UserAccount, QPair<QList<AnswerProtocol>, QList<AnswerProtocol>>> protocols;
        UserAccount selectedAccount;
        bool hasSelectedAccount;

        LiriResult selectedLiriResult;
        TorstonResult selectedTorstonResult;
        EnumTestType selectedResultType;
        bool hasSelectedResult;


    public:
        explicit PsychoResultWidget(QWidget *parent = nullptr);
        ~PsychoResultWidget();

        void changeAccountName(UserAccount account);
        void displayNewAccount(UserAccount account);
        void displayNewResult(LiriResult result);
        void displayNewResult(TorstonResult result);
        void displayUserAccounts(QList <UserAccount> accounts);
        void displayUserResults(QMap <UserAccount, QPair<QList<LiriResult>, QList<TorstonResult>>> results); //Ля шо творю
        void syncProtocols(QMap <UserAccount, QPair<QList<AnswerProtocol>, QList<AnswerProtocol>>> protocols);
        void removeDisplayedAccount(UserAccount account);
        void removeDisplayedResult(UserAccount account, LiriResult result);
        void removeDisplayedResult(UserAccount account, TorstonResult result);

    signals:
        void signalLiriResultClicked(LiriResult account);
        void signalTorstonResultClicked(TorstonResult account);
        void signalProtocolClicked(AnswerProtocol protocol);
        void signalDeleteLiriResult(UserAccount account, LiriResult result);
        void signalDeleteTorstonResult(UserAccount account, TorstonResult result);
        void signalPasswordChanged(QString passwd);
        void signalCancelButtonPressed();

    private slots:
        void onUserAccountClicked(UserAccount account);
        void onLiriResultClicked(LiriResult result);
        void onTorstonResultClicked(TorstonResult result);

        //Слоты для нажатия кнопок на панели
        void onShowResultButtonPressed();
        void onShowProtocolPressed();
        void onChangePasswdPressed();
        void onPrintButtonPressed();
        void onRemoveButtonPressed();
        void onCancelButtonPressed();

    private:
        void clearAccountsListWidgets();
        void clearResultsListWidgets();
        void onSelectResult();
        void onUnselectResult();
        void onPasswordChanged(QString newPassword);

        void printTorsronResult();
        void printLiriResult();


};

#endif // PSYCHORESULTWIDGET_H
