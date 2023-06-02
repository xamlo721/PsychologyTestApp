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

    static char readChar(QDomElement element, QString searchElementName);

    static unsigned char readUChar(QDomElement element, QString searchElementName);

    static short readShort(QDomElement element, QString searchElementName);

    static unsigned short readUShort(QDomElement element, QString searchElementName);

    static int readint(QDomElement element, QString searchElementName);

    static unsigned int readUint(QDomElement element, QString searchElementName);

    static long readLong(QDomElement element, QString searchElementName);//Кажется long на многих платформах 32

    static unsigned long readULong(QDomElement element, QString searchElementName);

    static QString readText(QDomElement element, QString searchElementName);

    static QList<char> readChars(QDomElement element, QString searchElementName);

    static QList<unsigned char> readUChars(QDomElement element, QString searchElementName);

    static QList<short> readShorts(QDomElement element, QString searchElementName);

    static QList<unsigned short> readUShorts(QDomElement element, QString searchElementName);

    static QList<int> readints(QDomElement element, QString searchElementName);

    static QList<unsigned int> readUints(QDomElement element, QString searchElementName);

    static QList<long> readLongs(QDomElement element, QString searchElementName);//Кажется long на многих платформах 32

    static QList<unsigned long> readULongs(QDomElement element, QString searchElementName);

    static QList<QString> readTexts(QDomElement element, QString searchElementName);

    static void writeChar(QDomElement element, QString searchElementName, char value);

    static void writeUChar(QDomElement element, QString searchElementName, unsigned char value);

    static void writeShort(QDomElement element, QString searchElementName, short value);

    static void writeUShort(QDomElement element, QString searchElementName, unsigned short value);

    static void writeint(QDomElement element, QString searchElementName, int value);

    static void writeUint(QDomElement element, QString searchElementName, unsigned int value);

    static void writeLong(QDomElement element, QString searchElementName, long value);//Кажется long на многих платформах 32

    static void writeULong(QDomElement element, QString searchElementName, unsigned long value);

    static void writeText(QDomElement element, QString searchElementName, QString value);

    static void writeChars(QDomElement element, QString searchElementName, QList<char> value);

    static void writeUChars(QDomElement element, QString searchElementName, QList<unsigned char> value);

    static void writeShorts(QDomElement element, QString searchElementName, QList<short> value);

    static void writeUShorts(QDomElement element, QString searchElementName, QList<unsigned short> value);

    static void writeInts(QDomElement element, QString searchElementName, QList<int> value);

    static void writeUints(QDomElement element, QString searchElementName, QList<unsigned int> value);

    static void writeLongs(QDomElement element, QString searchElementName, QList<long> value);//Кажется long на многих платформах 32

    static void writeULongs(QDomElement element, QString searchElementName, QList<unsigned long> value);

    static void writeTexts(QDomElement element, QString searchElementName, QList<QString> value);

    static QDomElement readSingleNode(QDomElement element, QString searchElementName);

    static QList<QDomElement> readMultiNode(QDomElement element, QString searchElementName);

signals:

};

#endif // XMLUTILS_H
