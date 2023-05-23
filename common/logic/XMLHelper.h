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

class XMLHelper : public QObject {

    Q_OBJECT

    public:
        explicit XMLHelper(QObject *parent = nullptr);

        QList<Test *> readTests(QString databasePath);

    private:
        Test * readTest(QDomElement testDomElement);
        Question * readQuestion(QDomElement testDomElement);
        Answer * readAnswer(QDomElement testDomElement);
        TestSection * readSection(QDomElement testDomElement);

    signals:

};

#endif // XMLHELPER_H
