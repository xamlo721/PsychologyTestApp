#ifndef APPLICATIONLOGIC_H
#define APPLICATIONLOGIC_H

#include <QObject>
#include <QMap>
#include <QQueue>

#include "common/items/Test.h"
#include "common/items/Answer.h"
#include "common/items/TestResult.h"
#include "common/items/Question.h"

class ApplicationLogic : public QObject {

    Q_OBJECT

    public:
        explicit ApplicationLogic(QObject *parent = nullptr);

        void setAvailableTests(QMap<EnumTestType, Test *> tests);

    signals:
        void signalAskQuestion(EnumTestType testType, Question q);

        void signalShowSectionDescription();//TODO: не уверен. что он нужен, ну на всякий случай

        void signalShowResult(TestResult result);

        void signalUpdateProgressBar(float completePercent);

    public slots:
        void onTestSelected(EnumTestType testType);

        void onTestStarted();

        void onQuestAnsweredLiri(bool asnwer);

        void onQuestAnsweredTorson(bool a1, bool a2, bool a3, bool a4 ,bool a5);

        void onSectionEnded();//TODO: пока не реализуется. Я спать хочу

        void onTestAborted();//В россии без абортов никуда

        void onTestEnded();

    private:
        QMap<EnumTestType, Test *> tests;
        Test * currentTest;
        Question currentQuest;
        QQueue<Question> questions;

        void calculateResult();



};

#endif // APPLICATIONLOGIC_H
