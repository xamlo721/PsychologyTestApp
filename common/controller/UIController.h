#ifndef UICONTROLLER_H
#define UICONTROLLER_H

#include <QObject>
#include "common/items/EnumTestType.h"
#include "common/items/Question.h"
#include "common/items/TestResult.h"
#include "common/items/LiriResult.h"

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

    public slots:

        void onAskQuestion(EnumTestType testType, Question q);

        void onShowTorstonResult(EnumTorsonResult result);

        void onShowLiriResult(LiriResult result);

        void onUpdateProgressBar(float completePercent);

        void onUpdateUserList(QList<UserAccount> users);

    private slots:
        void onAuthUser(UserAccount user);
        void onAddUser(QString user);
        void onEditUser(UserAccount user);
        void onDeleteUser(UserAccount user);


};

#endif // UICONTROLLER_H
