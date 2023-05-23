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

    QDomElement databaseDomElement = XmlUtils::readSingleNode(doc.documentElement(), "Database");

    QList<QDomElement> testsDomElements = XmlUtils::readMultiNode(databaseDomElement, "Test");

    for (QDomElement testDomElement : testsDomElements) {
        tests.append(this->readTest(testDomElement));
    }
    return tests;
}


Test * XMLHelper::readTest(QDomElement testDomElement) {

    EnumTestType testType;

    QDomElement sectionsDomElement = XmlUtils::readSingleNode(testDomElement, "Sections");

    QList<QDomElement> sectionListDomElement = XmlUtils::readMultiNode(testDomElement, "Sections");

    QMap<int, TestSection> sectionsList;
    for(QDomElement sectionDomElement : sectionListDomElement) {
        sectionsList.insert(sectionsList.size(), *this->readSection(sectionDomElement));
    }
    //Потом доедлаю, поезд через 2 часа!!! Test * test = new Test();
}

Question * XMLHelper::readQuestion(QDomElement testDomElement) {

}
Answer * XMLHelper::readAnswer(QDomElement testDomElement) {

}
TestSection * XMLHelper::readSection(QDomElement testDomElement) {

}

