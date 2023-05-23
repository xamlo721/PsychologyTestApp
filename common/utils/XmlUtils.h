#ifndef XMLUTILS_H
#define XMLUTILS_H

#include <QObject>
#include <QXmlStreamReader>

#include <QtXml/QDomAttr>
#include <QtXml/QDomCDATASection>
#include <QtXml/QDomCharacterData>
#include <QtXml/QDomComment>
#include <QtXml/QDomDocument>
#include <QtXml/QDomDocumentFragment>
#include <QtXml/QDomDocumentType>
#include <QtXml/QDomElement>
#include <QtXml/QDomEntity>
#include <QtXml/QDomEntityReference>

class XmlUtils : public QObject {

    Q_OBJECT

    public:
        explicit XmlUtils(QObject *parent = nullptr);

        static bool checkFile(QString databasePath);

        static QDomElement readSingleNode(QDomElement element, QString searchElementName);

        static QList<QDomElement> readMultiNode(QDomElement element, QString searchElementName);

    signals:

};

#endif // XMLUTILS_H
