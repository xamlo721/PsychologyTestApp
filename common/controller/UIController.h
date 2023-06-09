#ifndef UICONTROLLER_H
#define UICONTROLLER_H

#include <QObject>
#include "common/items/EnumTestType.h"
#include "common/items/Question.h"
#include "common/items/TestResult.h"
#include "common/items/LiriResult.h"
#include "common/items/TorstonResult.h"
#include "common/items/AnswerProtocol.h"

#include "common/ui/MainWindow.h"

class UIController : public QObject {
    Q_OBJECT

    private:
        MainWindow * window = 0;

    public:
        explicit UIController(QObject *parent = nullptr);

        void init();

        void setUI(MainWindow * window);


    signals:
        ///Сигнал о том, что был выбран тест
        void signalOpenTest(EnumTestType testType);

        void signalStartTest();

        void signalQuestAnsweredLiri(bool asnwer);

        void signalQuestAnsweredTorson(bool a1, bool a2, bool a3, bool a4);

        void signalAbortTest();

        void signalCompleteTest();

        void signalAuthUser(UserAccount user);
        void signalAddUser(QString user);
        void signalEditUser(UserAccount user);
        void signalDeleteUser(UserAccount user);
        void signalDeleteLiriResult(UserAccount account, LiriResult result);
        void signalDeleteTorstonResult(UserAccount account, TorstonResult result);

    public slots:

        void onAskQuestion(EnumTestType testType, Question q);

        void onShowTorstonResult(TorstonResult result);

        void onShowLiriResult(LiriResult result);

        void onUpdateProgressBar(float completePercent);

        void onUpdateUserList(QList<UserAccount> users);

        void onUpdateResultsList(QMap <UserAccount, QPair<QList<LiriResult>, QList<TorstonResult>>> results);

        void onUpdateProtocolList(QMap <UserAccount, QPair<QList<AnswerProtocol>, QList<AnswerProtocol>>> protocols);

    private slots:
        void onAuthUser(UserAccount user);
        void onAddUser(QString user);
        void onEditUser(UserAccount user);
        void onDeleteUser(UserAccount user);
        void onDeleteLiriResult(UserAccount account, LiriResult result);
        void onDeleteTorstonResult(UserAccount account, TorstonResult result);


};

#endif // UICONTROLLER_H
