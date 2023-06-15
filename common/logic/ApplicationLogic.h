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

#include "common/logic/LogicConstants.h"

class ApplicationLogic : public QObject {

    Q_OBJECT

    public:
        explicit ApplicationLogic(QObject *parent = nullptr);

        void setAvailableTests(QMap<EnumTestType, Test *> tests);

    signals:
        void signalAskQuestion(EnumTestType testType, Question q);

        void signalShowSectionDescription();//TODO: не уверен. что он нужен, ну на всякий случай

        void signalShowTorstonResult(EnumTorsonResult result);

        void signalShowLiriResult(LiriResult result);

        void signalUpdateProgressBar(float completePercent);

    public slots:
        void onTestSelected(EnumTestType testType);

        void onTestStarted(QString user);

        void onQuestAnsweredLiri(bool asnwer);

        void onQuestAnsweredTorson(bool a1, bool a2, bool a3, bool a4);

        void onSectionEnded();//TODO: пока не реализуется. Я спать хочу

        void onTestAborted();//В россии без абортов никуда

        void onTestEnded();

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

        QString currentUser;

        EnumTorsonResult calculateTorstonResult();
        void sendLiriResult();


};

#endif // APPLICATIONLOGIC_H
