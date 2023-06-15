#include "ApplicationLogic.h"
#include <QDebug>

ApplicationLogic::ApplicationLogic(QObject *parent) : QObject(parent) {

}

void ApplicationLogic::setAvailableTests(QMap<EnumTestType, Test *> tests) {
    this->tests = tests;
}

void ApplicationLogic::onTestSelected(EnumTestType testType) {

    if (!tests.contains(testType)) {
        throw std::runtime_error(QString("[ApplicationLogic] Error loading Test!").toLocal8Bit().constData());
    }

    this->currentTest = tests.value(testType);

    //Запихнуть тест в очередь вопросов
    for (int s = 0; s < currentTest->getSections().size(); s++) {

        TestSection section = currentTest->getSections().value(s);
        for (int i = 0; i < section.getQuestions().size(); i ++) {
            this->questions.append(section.getQuestions().value(i));
        }

    }

    questionsSize = this->questions.size();

}

void ApplicationLogic::onTestStarted(QString user) {

    this->currentUser = user;
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

void ApplicationLogic::onQuestAnsweredTorson(bool a1, bool a2, bool a3, bool a4 ) {
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

    if (questions.empty()) {
        qDebug() << "calculating torson";
        emit signalShowTorstonResult(calculateTorstonResult());

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


}

EnumTorsonResult ApplicationLogic::calculateTorstonResult() {
    LogicConstants testLogic;
    int torsonPoitns =testLogic.convertTorsonRawState(this->rawTorston);
    return testLogic.getTorsonResult(torsonPoitns);
}

void ApplicationLogic::sendLiriResult() {

    emit signalShowLiriResult(LiriResult(
                param1 * 100.f/16,
                param2 * 100.f/16,
                param3 * 100.f/16,
                param4 * 100.f/16,
                param5 * 100.f/16,
                param6 * 100.f/16,
                param7 * 100.f/16,
                param8 * 100.f/16));
}
