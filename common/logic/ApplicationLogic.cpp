#include "ApplicationLogic.h"
#include <QDebug>

ApplicationLogic::ApplicationLogic(QObject *parent) : QObject(parent) {

}

void ApplicationLogic::setAvailableTests(QMap<EnumTestType, Test *> tests) {
    this->tests = tests;
}

void ApplicationLogic::onAuthUser(UserAccount user) {
    this->currentUser = user;
}

void ApplicationLogic::onAddUser(QString user) {


    for (int i = 0; i < users.size(); i++) {
        UserAccount account = users.at(i);
        if (account.getName() == user) {
            return;
        }
    }

    this->users.append(UserAccount(this->availableUserId++, user));

    emit signalUpdateUserList(this->users);

}

void ApplicationLogic::onEditUser(UserAccount user) {

//    bool contains;
//    UserAccount oldAccount;

    for (UserAccount acc : this->users) {
        if (acc.getID() == user.getID()) {
            this->users.removeOne(acc);
            acc.changeUserName(user.getName());
            this->users.append(acc);
        }
    }
//    if (!users.contains(user)) {
//        //TODO:
//        return;
//    }

    //this->users.append(user);

    emit signalUpdateUserList(this->users);
}

void ApplicationLogic::onDeleteUser(UserAccount user) {


    if (!users.contains(user)) {
        //TODO:
        return;
    }

    this->users.removeOne(user);

    emit signalUpdateUserList(this->users);
}

void ApplicationLogic::onDeleteLiriResult(UserAccount account, LiriResult result) {
    QPair<QList<LiriResult>, QList<TorstonResult>> userAllResults = this->results.value(account);

    QList<LiriResult> userLiriResults = userAllResults.first;
    userLiriResults.removeOne(result);

    userAllResults.first = userLiriResults;

    this->results.insert(account, userAllResults);

    emit signalUpdateResultsList(this->results);
}

void ApplicationLogic::onDeleteTorstonResult(UserAccount account, TorstonResult result) {
    QPair<QList<LiriResult>, QList<TorstonResult>> userAllResults = this->results.value(account);

    QList<TorstonResult> userTorstonResults = userAllResults.second;
    userTorstonResults.removeOne(result);

    userAllResults.second = userTorstonResults;

    this->results.insert(account, userAllResults);

    emit signalUpdateResultsList(this->results);
}

void ApplicationLogic::onTestSelected(EnumTestType testType) {

    //Ну и костыль, господи...
    this->currentAnswerProtocol.answers.first.clear();
    this->currentAnswerProtocol.answers.second.clear();
    this->currentAnswerProtocol.resultID = this->availableLiriResultId + this->availableTorstonResultId;


    if (!tests.contains(testType)) {
        throw std::runtime_error(QString("[ApplicationLogic] Error loading Test!").toLocal8Bit().constData());
    }

    this->currentTest = tests.value(testType);

    int questionCounter = 1;
    //Запихнуть тест в очередь вопросов
    for (int s = 0; s < currentTest->getSections().size(); s++) {
        TestSection section = currentTest->getSections().value(s);
        for (int i = 0; i < section.getQuestions().size(); i ++) {
            Question q = section.getQuestions().value(i);
            this->questions.append(q);
            if (testType == EnumTestType::Liri) {
                currentAnswerProtocol.answers.first.append(q.getText());
            } else {
                currentAnswerProtocol.answers.first.append(QString::number(questionCounter++));
            }
        }
    }

    questionsSize = this->questions.size();

}

void ApplicationLogic::onTestStarted() {
    //TODO:

    rawTorston = 0;
    rawLiri = 0;

    this->liriQuestionNumber = 1;
    this->param1 = 0;
    this->param2 = 0;
    this->param3 = 0;
    this->param4 = 0;
    this->param5 = 0;
    this->param6 = 0;
    this->param7 = 0;
    this->param8 = 0;


    currentQuest = questions.takeFirst();

    emit signalAskQuestion(this->currentTest->getTestType(), currentQuest);

    emit signalUpdateProgressBar(0);
}

void ApplicationLogic::onQuestAnsweredLiri(bool answer) {


    if (       (liriQuestionNumber >= 1 && liriQuestionNumber <= 4) || (liriQuestionNumber >= 33 && liriQuestionNumber <= 36) || (liriQuestionNumber >= 65 && liriQuestionNumber <= 68) || (liriQuestionNumber >= 97 && liriQuestionNumber <= 100)){
        this->param1 += answer;
    } else if ((liriQuestionNumber >= 5 && liriQuestionNumber <= 8) || (liriQuestionNumber >= 37 && liriQuestionNumber <= 40) || (liriQuestionNumber >= 69 && liriQuestionNumber <= 72) || (liriQuestionNumber >= 101 && liriQuestionNumber <= 104)){
        this->param2 += answer;
    } else if ((liriQuestionNumber >= 9 && liriQuestionNumber <= 12) || (liriQuestionNumber >= 41 && liriQuestionNumber <= 44) || (liriQuestionNumber >= 73 && liriQuestionNumber <= 76) || (liriQuestionNumber >= 105 && liriQuestionNumber <= 108)){
        this->param3 += answer;
    } else if ((liriQuestionNumber >= 13 && liriQuestionNumber <= 16) || (liriQuestionNumber >= 45 && liriQuestionNumber <= 48) || (liriQuestionNumber >= 77 && liriQuestionNumber <= 80) || (liriQuestionNumber >= 109 && liriQuestionNumber <= 112)){
        this->param4 += answer;
    } else if ((liriQuestionNumber >= 17 && liriQuestionNumber <= 20) || (liriQuestionNumber >= 49 && liriQuestionNumber <= 52) || (liriQuestionNumber >= 81 && liriQuestionNumber <= 84) || (liriQuestionNumber >= 113 && liriQuestionNumber <= 116)){
        this->param5 += answer;
    } else if ((liriQuestionNumber >= 21 && liriQuestionNumber <= 24) || (liriQuestionNumber >= 53 && liriQuestionNumber <= 56) || (liriQuestionNumber >= 85 && liriQuestionNumber <= 88) || (liriQuestionNumber >= 117 && liriQuestionNumber <= 120)){
        this->param6 += answer;
    } else if ((liriQuestionNumber >= 25 && liriQuestionNumber <= 28) || (liriQuestionNumber >= 57 && liriQuestionNumber <= 60) || (liriQuestionNumber >= 89 && liriQuestionNumber <= 92) || (liriQuestionNumber >= 121 && liriQuestionNumber <= 124)){
        this->param7 += answer;
    } else if ((liriQuestionNumber >= 29 && liriQuestionNumber <= 32) || (liriQuestionNumber >= 61 && liriQuestionNumber <= 64) || (liriQuestionNumber >= 93 && liriQuestionNumber <= 96) || (liriQuestionNumber >= 125 && liriQuestionNumber <= 128)){
        this->param8 += answer;
    }


    if (answer) {
        currentAnswerProtocol.answers.second.append( "Да");
    } else {
        currentAnswerProtocol.answers.second.append( "Нет");
    }


    this->liriQuestionNumber++;

    // По ключу подсчитывается количество сырых очков
    // в соответствии с правильными ответами, которые
    // по таблице переводятся в стандартные баллы.

    if (questions.empty()) {

        sendLiriResult();

        return;
    }
    currentQuest = questions.takeFirst();

    emit signalAskQuestion(this->currentTest->getTestType(), currentQuest);

    emit signalUpdateProgressBar(1.0f - (float)this->questions.size() / (float)questionsSize );

}

void ApplicationLogic::onQuestAnsweredTorston(bool a1, bool a2, bool a3, bool a4 ) {
    QMap<int, Answer> answers = currentQuest.getAnswers();

    Answer answer1 =answers.value(0);
    Answer answer2 =answers.value(1);
    Answer answer3 =answers.value(2);
    Answer answer4 =answers.value(3);

    this->rawTorston += answer1.isTrue() == a1;
    this->rawTorston += answer2.isTrue() == a2;
    this->rawTorston += answer3.isTrue() == a3;
    this->rawTorston += answer4.isTrue() == a4;

    // По ключу подсчитывается количество сырых очков
    // в соответствии с правильными ответами, которые
    // по таблице переводятся в стандартные баллы.

    QString result;

    if (a1) {
        result.append(" Да");
    } else {
        result.append(" Нет");
    }

    if (a2) {
        result.append(" Да");
    } else {
        result.append(" Нет");
    }

    if (a3) {
        result.append(" Да");
    } else {
        result.append(" Нет");
    }

    if (a4) {
        result.append(" Да");
    } else {
        result.append(" Нет");
    }

    currentAnswerProtocol.answers.second.append(result);


    if (questions.empty()) {

        this->sendTorstonResult();

        return;
    }
    currentQuest = questions.takeFirst();

    emit signalAskQuestion(this->currentTest->getTestType(),currentQuest);

    emit signalUpdateProgressBar(1.0f - (float)this->questions.size() / (float)questionsSize);

}

void ApplicationLogic::onSectionEnded() {
    //TODO: По идее, я должен отправить заставку о новой секции
    //Но надо подумать, что надо ли оно по факту
}


void ApplicationLogic::onTestAborted() {
    this->questions.clear();
   //TODO: Сбросить выполнение и перейти в режим готовности

}

void ApplicationLogic::onTestEnded() {

    //TODO: Сбросить все счётчики и т.д
    emit signalUpdateResultsList(this->results);


}

EnumTorsonResult ApplicationLogic::calculateTorstonResult() {
    LogicConstants testLogic;
    int torsonPoitns =testLogic.convertTorsonRawState(this->rawTorston);
    return testLogic.getTorsonResult(torsonPoitns);
}

void ApplicationLogic::sendTorstonResult() {

    TorstonResult torston(this->availableTorstonResultId++, this->currentUser, calculateTorstonResult());

    if (!this->results.contains(this->currentUser)) {
        this->results.insert(this->currentUser, QPair<QList<LiriResult>, QList<TorstonResult>>());
    }

    QPair<QList<LiriResult>, QList<TorstonResult>> userAllResults = this->results.value(this->currentUser);

    QList<TorstonResult> userTorstonResults = userAllResults.second;
    userTorstonResults.append(torston);

    userAllResults.second = userTorstonResults;

    QPair<QList<AnswerProtocol>, QList<AnswerProtocol>> allUserProtocols = this->protocols.value(this->currentUser);
    allUserProtocols.second.append(AnswerProtocol(torston.resultID, this->currentAnswerProtocol.answers));
    this->protocols.insert(this->currentUser, allUserProtocols);

    this->results.insert(this->currentUser, userAllResults);

    emit signalUpdateProtocols(this->protocols);

    emit signalUpdateResultsList(this->results);

    emit signalShowTorstonResult(torston);

}


void ApplicationLogic::sendLiriResult() {

    LiriResult liri(this->availableLiriResultId++,
                    this->currentUser,
                    param1 * 100.f/16,
                    param2 * 100.f/16,
                    param3 * 100.f/16,
                    param4 * 100.f/16,
                    param5 * 100.f/16,
                    param6 * 100.f/16,
                    param7 * 100.f/16,
                    param8 * 100.f/16);

    if (!this->results.contains(this->currentUser)) {
        this->results.insert(this->currentUser, QPair<QList<LiriResult>, QList<TorstonResult>>());
    }

    QPair<QList<LiriResult>, QList<TorstonResult>> userAllResults = this->results.value(this->currentUser);

    QList<LiriResult> userLiriResults = userAllResults.first;
    userLiriResults.append(liri);

    userAllResults.first = userLiriResults;

    this->results.insert(this->currentUser, userAllResults);


    QPair<QList<AnswerProtocol>, QList<AnswerProtocol>> allUserProtocols = this->protocols.value(this->currentUser);
    allUserProtocols.first.append(AnswerProtocol(liri.resultID, this->currentAnswerProtocol.answers));
    this->protocols.insert(this->currentUser, allUserProtocols);

    emit signalUpdateProtocols(this->protocols);

    emit signalUpdateResultsList(this->results);

    emit signalShowLiriResult(liri);
}
