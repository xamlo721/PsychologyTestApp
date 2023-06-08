#ifndef UICONTROLLER_H
#define UICONTROLLER_H

#include <QObject>
#include "common/items/EnumTestType.h"
#include "common/items/Question.h"
#include "common/items/TestResult.h"

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

        void signalStartTest(EnumTestType testType);

        void signalQuestAnsweredLiri(bool asnwer);

        void signalQuestAnsweredTorson(bool a1, bool a2, bool a3, bool a4);

        void signalAbortTest();

        void signalCompleteTest();

    public slots:

        void onAskQuestion(EnumTestType testType, Question q);

        void onShowTorstonResult(QString result);

        void onShowLiriResult(int st1, int st2,int st3,int st4,int st5,int st6,int st7,int st8);

        void onUpdateProgressBar(float completePercent);




};

#endif // UICONTROLLER_H
