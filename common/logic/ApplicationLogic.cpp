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
    for (int s = 0; s < currentTest->getSections().size(); s++) {

        TestSection section = currentTest->getSections().value(s);
        for (int i = 0; i < section.getQuestions().size(); i ++) {
            this->questions.append(section.getQuestions().value(i));
        }

    }

    questionsSize = this->questions.size();

}

void ApplicationLogic::onTestStarted() {

    //TODO:

    rawTorston = 0;
    rawLiri = 0;

    currentQuest = questions.takeFirst();

    emit signalAskQuestion(this->currentTest->getTestType(), currentQuest);

    emit signalUpdateProgressBar(0);
}

void ApplicationLogic::onQuestAnsweredLiri(bool answer) {

    //TODO:Сделать что-то с ответом

    // По ключу подсчитывается количество сырых очков
    // в соответствии с правильными ответами, которые
    // по таблице переводятся в стандартные баллы.

    if (questions.empty()) {

        emit signalShowResult(calculateResult());

        return;
    }
    currentQuest = questions.takeFirst();

    emit signalAskQuestion(this->currentTest->getTestType(), currentQuest);

    emit signalUpdateProgressBar(1.0f - (float)this->questions.size() / (float)questionsSize );

}

void ApplicationLogic::onQuestAnsweredTorson(bool a1, bool a2, bool a3, bool a4 ) {

    //TODO:Сделать что-то с ответом


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

        emit signalShowResult(calculateResult());

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

   //TODO: Сбросить выполнение и перейти в режим готовности

}

void ApplicationLogic::onTestEnded() {

    //TODO: Сбросить все счётчики и т.д


}

QString ApplicationLogic::calculateResult() {

    QString result;// = this->currentTest->getTestResult().getText();
    LogicConstants testLogic;

    if (this->currentTest->getTestType() == EnumTestType::Liri) {

    } else {

        int torsonPoitns =testLogic.convertTorsonRawState(this->rawTorston);

        result.append("Поздравляем! Вы закончили тест Торстона!"
                      "Ваш результат: ");
        switch (testLogic.getTorsonResult(torsonPoitns)) {

            case LogicConstants::EnumTorsonResult::VeryLow : {
                result.append("Очень низкий");
                break;
            }

            case LogicConstants::EnumTorsonResult::Low : {
                result.append("Низкий");
                break;
            }

            case LogicConstants::EnumTorsonResult::Medium : {
                result.append("Средний");
                break;
            }

            case LogicConstants::EnumTorsonResult::High : {
                result.append("Высокий");
                break;
            }

            case LogicConstants::EnumTorsonResult::VeryHigh : {
                result.append("Очень высокий");
                break;
            }

        }

    }

    return result;
}
