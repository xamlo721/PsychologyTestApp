#ifndef XMLHELPER_H
#define XMLHELPER_H

#include <QObject>
#include <QFile>
#include <QList>
#include <QtXml/QDomElement>

#include "common/items/Test.h"
#include "common/items/Question.h"
#include "common/items/Answer.h"
#include "common/items/TestSection.h"
#include "common/items/EnumTestType.h"
#include "common/items/TestResult.h"

class XMLHelper : public QObject {

    Q_OBJECT

    public:
        explicit XMLHelper(QObject *parent = nullptr);

        static QList<Test *> readTests(QString databasePath);

    private:
        static Test * readTest(QDomElement testDomElement);
        static Question readQuestion(QDomElement testDomElement);
        static Answer readAnswer(QDomElement testDomElement);
        static TestSection readSection(QDomElement testDomElement);
        static TestResult readResult(QDomElement testDomElement);
        static EnumTestType readTestType(QDomElement testDomElement);

    signals:

};

#endif // XMLHELPER_H
