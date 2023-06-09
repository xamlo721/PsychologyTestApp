#ifndef APPLICATIONLOGIC_H
#define APPLICATIONLOGIC_H

#include <QObject>
#include <QMap>
#include <QQueue>

#include "common/items/Test.h"
#include "common/items/Answer.h"
#include "common/items/TestResult.h"
#include "common/items/Question.h"

#include "common/logic/LogicConstants.h"

class ApplicationLogic : public QObject {

    Q_OBJECT

    public:
        explicit ApplicationLogic(QObject *parent = nullptr);

        void setAvailableTests(QMap<EnumTestType, Test *> tests);

    signals:
        void signalAskQuestion(EnumTestType testType, Question q);

        void signalShowSectionDescription();//TODO: не уверен. что он нужен, ну на всякий случай

        void signalShowTorstonResult(QString result);

        void signalShowLiriResult(int st1, int st2,int st3,int st4,int st5,int st6,int st7,int st8);

        void signalUpdateProgressBar(float completePercent);

    public slots:
        void onTestSelected(EnumTestType testType);

        void onTestStarted();

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

        QString calculateTorstonResult();
        void sendLiriResult();


};

#endif // APPLICATIONLOGIC_H
