#ifndef APPLICATIONLOGIC_H
#define APPLICATIONLOGIC_H

#include <QObject>
#include <QMap>
#include <QQueue>

#include "common/items/Test.h"
#include "common/items/Answer.h"
#include "common/items/TestResult.h"
#include "common/items/Question.h"
#include "common/items/EnumTorsonResult.h"
#include "common/items/LiriResult.h"
#include "common/items/TorstonResult.h"

#include "common/logic/LogicConstants.h"

#include "common/items/UserAccount.h"
#include "common/items/AnswerProtocol.h"


class ApplicationLogic : public QObject {

    Q_OBJECT

    public:
        explicit ApplicationLogic(QObject *parent = nullptr);

        void setAvailableTests(QMap<EnumTestType, Test *> tests);

    signals:
        void signalAskQuestion(EnumTestType testType, Question q);

        void signalShowSectionDescription();//TODO: не уверен. что он нужен, ну на всякий случай

        void signalShowTorstonResult(TorstonResult result);

        void signalShowLiriResult(LiriResult result);

        void signalUpdateProgressBar(float completePercent);

        void signalUpdateUserList(QList<UserAccount> users);

        void signalUpdateResultsList(QMap <UserAccount, QPair<QList<LiriResult>, QList<TorstonResult>>> results);

        void signalUpdateProtocols(QMap <UserAccount, QPair<QList<AnswerProtocol>, QList<AnswerProtocol>>> protocols);

    public slots:
        void onTestSelected(EnumTestType testType);

        void onTestStarted();

        void onQuestAnsweredLiri(bool asnwer);

        void onQuestAnsweredTorston(bool a1, bool a2, bool a3, bool a4);

        void onSectionEnded();//TODO: пока не реализуется. Я спать хочу

        void onTestAborted();//В россии без абортов никуда

        void onTestEnded();

        void onAuthUser(UserAccount user);

        void onAddUser(QString user);

        void onEditUser(UserAccount user);

        void onDeleteUser(UserAccount user);

        void onDeleteLiriResult(UserAccount account, LiriResult result);

        void onDeleteTorstonResult(UserAccount account, TorstonResult result);


    private:
        QMap<EnumTestType, Test *> tests;
        Test * currentTest;
        Question currentQuest;
        QQueue<Question> questions;

        int questionsSize = 0;

        int rawTorston = 0;
        int rawLiri = 0;

        //Блок очень странных маркеров для теста Лири
        int liriQuestionNumber = 1;
        int param1 = 0;
        int param2 = 0;
        int param3 = 0;
        int param4 = 0;
        int param5 = 0;
        int param6 = 0;
        int param7 = 0;
        int param8 = 0;

        UserAccount currentUser;

        int availableUserId = 0;
        int availableLiriResultId = 1;
        int availableTorstonResultId = 1;

        EnumTorsonResult calculateTorstonResult();
        void sendLiriResult();
        void sendTorstonResult();

        QList<UserAccount> users;
        QMap <UserAccount, QPair<QList<LiriResult>, QList<TorstonResult>>> results;
        QMap <UserAccount, QPair<QList<AnswerProtocol>, QList<AnswerProtocol>>> protocols;

        AnswerProtocol currentAnswerProtocol;

};

#endif // APPLICATIONLOGIC_H
