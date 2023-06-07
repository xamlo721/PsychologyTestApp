#include "ApplicationLogic.h"

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
//    for (int s = 0; s < currentTest->getSections().size(); s++) {

//        TestSection section = currentTest->getSections().value(s);
//        for (int i = 0; i < section.getQuestions().size(); i ++) {
//            this->questions.append(section.getQuestions().value(i));
//        }

//    }

}

void ApplicationLogic::onTestStarted() {
    //TODO:
    emit signalAskQuestion(questions.takeFirst());
}

void ApplicationLogic::onQuestAnsweredLiri(bool answer) {

    //TODO:Сделать что-то с ответом

    // По ключу подсчитывается количество сырых очков
    // в соответствии с правильными ответами, которые
    // по таблице переводятся в стандартные баллы.

    emit signalAskQuestion(questions.takeFirst());

}

void ApplicationLogic::onQuestAnsweredTorson(bool a1, bool a2, bool a3, bool a4 ,bool a5) {

    //TODO:Сделать что-то с ответом

    // По ключу подсчитывается количество сырых очков
    // в соответствии с правильными ответами, которые
    // по таблице переводятся в стандартные баллы.

    emit signalAskQuestion(questions.takeFirst());
}

void ApplicationLogic::onSectionEnded() {
    //TODO: По идее, я должен отправить заставку о новой секции
    //Но надо подумать, что надо ли оно по факту
}


void ApplicationLogic::onTestAborted() {
   //TODO: Сбросить выполнение и перейти в режим готовности
}

void ApplicationLogic::onTestEnded() {
    //TODO: Посчитать результат
}

void ApplicationLogic::calculateResult() {
    if (this->currentTest->getTestType() == EnumTestType::Liri) {

    } else {

    }

}
