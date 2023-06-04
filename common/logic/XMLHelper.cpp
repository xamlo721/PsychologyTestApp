#include "XMLHelper.h"

#include<QDebug>


#include "common/utils/XmlUtils.h"

XMLHelper::XMLHelper(QObject *parent) : QObject(parent) {

}

QList<Test *> XMLHelper::readTests(QString databasePath) {

    QList<Test *> tests;

    if (!XmlUtils::checkFile(databasePath)) {
        return tests;
    }

    QFile file(databasePath);
    file.open(QFile::ReadOnly | QFile::Text);

    QDomDocument doc;
    doc.setContent(&file);

    file.seek(0); // Сбросить позицию чтения файла до начала

    QList<QDomElement> testsDomElements = XmlUtils::readMultiNode(doc.documentElement(), "Test");

    for (QDomElement testDomElement : testsDomElements) {
        tests.append(XMLHelper::readTest(testDomElement));
    }
    return tests;
}


Test * XMLHelper::readTest(QDomElement testDomElement) {

    //QDomElement nameDomElement = XmlUtils::readSingleNode(testDomElement, "Name");
    EnumTestType testType = XMLHelper::readTestType(testDomElement);

    QDomElement sectionsDomElement = XmlUtils::readSingleNode(testDomElement, "Sections");

    QList<QDomElement> sectionListDomElement = XmlUtils::readMultiNode(testDomElement, "Section");

    QMap<int, TestSection> sectionsList;
    for(QDomElement sectionDomElement : sectionListDomElement) {
        sectionsList.insert(sectionsList.size(), XMLHelper::readSection(sectionDomElement));
    }

    //QDomElement resultDomElement = XmlUtils::readSingleNode(testDomElement, "Result");
    TestResult testResult = XMLHelper::readResult(testDomElement);

    Test * test = new Test(testType, sectionsList, testResult);
    return test;
}

Question XMLHelper::readQuestion(QDomElement testDomElement) {
    QString questionText = XmlUtils::readText(testDomElement, "Text");
    QString imagePath = XmlUtils::readText(testDomElement, "ImagePath");

    QDomElement answersDomElement = XmlUtils::readSingleNode(testDomElement, "Answers");
    QList<QDomElement> answerListDomElement = XmlUtils::readMultiNode(answersDomElement, "Answer");

    QMap<int, Answer> answerList;
    for(QDomElement answerDomElement : answerListDomElement) {
        answerList.insert(answerList.size(), XMLHelper::readAnswer(answerDomElement));
    }

    if (imagePath.isEmpty()) {
        return Question(questionText, answerList);
    } else {
        return Question(questionText, answerList, true, imagePath);
    }
}

Answer XMLHelper::readAnswer(QDomElement testDomElement) {
    QString answerText = XmlUtils::readText(testDomElement, "Text");
    QString imagePath = XmlUtils::readText(testDomElement, "ImagePath");
    bool isCorrectAnswer = XmlUtils::readText(testDomElement, "IsCorrect") == "true";
    if (imagePath.isEmpty()) {
        return Answer(answerText, isCorrectAnswer);
    } else {
        return Answer(answerText, isCorrectAnswer, imagePath);
    }
}

TestSection XMLHelper::readSection(QDomElement testDomElement) {
    QString sectionText = XmlUtils::readText(testDomElement, "Text");
    QString imagePath = XmlUtils::readText(testDomElement, "ImagePath");

    QDomElement questionsDomElement = XmlUtils::readSingleNode(testDomElement, "Questions");
    QList<QDomElement> questionListDomElement = XmlUtils::readMultiNode(questionsDomElement, "Question");

    QMap<int, Question> questionList;
    for(QDomElement answerDomElement : questionListDomElement) {
        questionList.insert(questionList.size(), XMLHelper::readQuestion(answerDomElement));
    }

    if (imagePath.isEmpty()) {
        return TestSection(sectionText, questionList);
    } else {
        return TestSection(sectionText, questionList, true, imagePath);
    }
}

TestResult XMLHelper::readResult(QDomElement testDomElement) {
    return XmlUtils::readText(testDomElement, "Result");
}

EnumTestType XMLHelper::readTestType(QDomElement testDomElement) {
    QString testName = XmlUtils::readText(testDomElement, "Name");
    if (testName == "Liri") {
        return EnumTestType::Liri;
    } else if (testName == "Torston") {
        return EnumTestType::Torston;
    } else {
        throw std::runtime_error(QString("[XMLHelper] Error reading EnumTestType!").toLocal8Bit().constData());
    }
}

