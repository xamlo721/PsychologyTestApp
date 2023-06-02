#include "XmlUtils.h"
#include <QFile>
#include <QDebug>

#include <stdexcept>
#include <exception>

XmlUtils::XmlUtils(QObject *parent) : QObject(parent) {

}

bool XmlUtils::checkFile(QString databasePath) {

    QFile file(databasePath);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "Failed to open database file";
        return false;
    }

    QDomDocument doc;

    if (!doc.setContent(&file)) {
        file.close();
        return false;
    }

    file.seek(0); // Сбросить позицию чтения файла до начала

    QXmlStreamReader xml(&file);

    while (!xml.atEnd() && !xml.hasError()) {
        QXmlStreamReader::TokenType token = xml.readNext();
        if (token == QXmlStreamReader::Invalid) {
            qDebug() << "Error: file format is not valid XML";
            return false;
        }
    }

    if (xml.hasError()) {
        qDebug() << "Error:" << xml.errorString();
        return false;
    }

    file.close();

    return true;

}

char XmlUtils::readChar(QDomElement element, QString searchElementName) {
    return element.elementsByTagName(searchElementName).at(0).toElement().text().at(0).row();
}

unsigned char XmlUtils::readUChar(QDomElement element, QString searchElementName) {
    return element.elementsByTagName(searchElementName).at(0).toElement().text().at(0).row();
}

short XmlUtils::readShort(QDomElement element, QString searchElementName) {
    return element.elementsByTagName(searchElementName).at(0).toElement().text().toShort();
}

unsigned short XmlUtils::readUShort(QDomElement element, QString searchElementName) {
    return element.elementsByTagName(searchElementName).at(0).toElement().text().toUShort();
}

int XmlUtils::readint(QDomElement element, QString searchElementName) {
    return element.elementsByTagName(searchElementName).at(0).toElement().text().toInt();
}

unsigned int XmlUtils::readUint(QDomElement element, QString searchElementName) {
    return element.elementsByTagName(searchElementName).at(0).toElement().text().toUInt();
}

long XmlUtils::readLong(QDomElement element, QString searchElementName) {    //Кажется long на многих платформах 32
    return element.elementsByTagName(searchElementName).at(0).toElement().text().toLong();
}

unsigned long XmlUtils::readULong(QDomElement element, QString searchElementName) {
    return element.elementsByTagName(searchElementName).at(0).toElement().text().toULong();
}

QString XmlUtils::readText(QDomElement element, QString searchElementName) {
    return element.elementsByTagName(searchElementName).at(0).toElement().text();
}

QList<char> XmlUtils::readChars(QDomElement element, QString searchElementName) {
    QList<char> values;
    QDomNodeList elements = element.elementsByTagName(searchElementName);
    for (int i = 0; i < elements.size(); i++ ) {
        QDomNode em = elements.at(i);
        values.append(em.toElement().text().at(0).row());
    }
    return values;
}


QList<unsigned char> XmlUtils::readUChars(QDomElement element, QString searchElementName) {
    QList<unsigned char> values;
    QDomNodeList elements = element.elementsByTagName(searchElementName);
    for (int i = 0; i < elements.size(); i++ ) {
        QDomNode em = elements.at(i);
        values.append(em.toElement().text().at(0).row());
    }
    return values;
}


QList<short> XmlUtils::readShorts(QDomElement element, QString searchElementName) {
    QList<short> values;
    QDomNodeList elements = element.elementsByTagName(searchElementName);
    for (int i = 0; i < elements.size(); i++ ) {
        QDomNode em = elements.at(i);
        values.append(em.toElement().text().toShort());
    }
    return values;
}


QList<unsigned short> XmlUtils::readUShorts(QDomElement element, QString searchElementName) {
    QList<unsigned short> values;
    QDomNodeList elements = element.elementsByTagName(searchElementName);
    for (int i = 0; i < elements.size(); i++ ) {
        QDomNode em = elements.at(i);
        values.append(em.toElement().text().toUShort());
    }
    return values;
}


QList<int> XmlUtils::readints(QDomElement element, QString searchElementName) {
    QList<int> values;
    QDomNodeList elements = element.elementsByTagName(searchElementName);
    for (int i = 0; i < elements.size(); i++ ) {
        QDomNode em = elements.at(i);
        values.append(em.toElement().text().toInt());
    }
    return values;
}


QList<unsigned int> XmlUtils::readUints(QDomElement element, QString searchElementName) {
    QList<unsigned int> values;
    QDomNodeList elements = element.elementsByTagName(searchElementName);
    for (int i = 0; i < elements.size(); i++ ) {
        QDomNode em = elements.at(i);
        values.append(em.toElement().text().toUInt());
    }
    return values;
}


QList<long> XmlUtils::readLongs(QDomElement element, QString searchElementName) { //Кажется long на многих платформах 32
    QList<long> values;
    QDomNodeList elements = element.elementsByTagName(searchElementName);
    for (int i = 0; i < elements.size(); i++ ) {
        QDomNode em = elements.at(i);
        values.append(em.toElement().text().toLong());
    }
    return values;
}

QList<unsigned long> XmlUtils::readULongs(QDomElement element, QString searchElementName) {
    QList<unsigned long> values;
    QDomNodeList elements = element.elementsByTagName(searchElementName);
    for (int i = 0; i < elements.size(); i++ ) {
        QDomNode em = elements.at(i);
        values.append(em.toElement().text().toULong());
    }
    return values;
}


QList<QString> XmlUtils::readTexts(QDomElement element, QString searchElementName) {
    QList<QString> values;
    QDomNodeList elements = element.elementsByTagName(searchElementName);
    for (int i = 0; i < elements.size(); i++ ) {
        QDomNode em = elements.at(i);
        values.append(em.toElement().text());
    }
    return values;
}


void XmlUtils::writeChar(QDomElement element, QString searchElementName, char value) {

}


void XmlUtils::writeUChar(QDomElement element, QString searchElementName, unsigned char value) {

}


void XmlUtils::writeShort(QDomElement element, QString searchElementName, short value) {

}


void XmlUtils::writeUShort(QDomElement element, QString searchElementName, unsigned short value) {

}


void XmlUtils::writeint(QDomElement element, QString searchElementName, int value) {

}


void XmlUtils::writeUint(QDomElement element, QString searchElementName, unsigned int value) {

}


void XmlUtils::writeLong(QDomElement element, QString searchElementName, long value) { //Кажется long на многих платформах 32

}

void XmlUtils::writeULong(QDomElement element, QString searchElementName, unsigned long value) {

}


void XmlUtils::writeText(QDomElement element, QString searchElementName, QString value) {

}


void XmlUtils::writeChars(QDomElement element, QString searchElementName, QList<char> value) {

}


void XmlUtils::writeUChars(QDomElement element, QString searchElementName, QList<unsigned char> value) {

}


void XmlUtils::writeShorts(QDomElement element, QString searchElementName, QList<short> value) {

}


void XmlUtils::writeUShorts(QDomElement element, QString searchElementName, QList<unsigned short> value) {

}


void XmlUtils::writeInts(QDomElement element, QString searchElementName, QList<int> value) {

}

void XmlUtils::writeUints(QDomElement element, QString searchElementName, QList<unsigned int> value)  {

}


void XmlUtils::writeLongs(QDomElement element, QString searchElementName, QList<long> value) { //Кажется long на многих платформах 32

}

void XmlUtils::writeULongs(QDomElement element, QString searchElementName, QList<unsigned long> value) {

}


void XmlUtils::writeTexts(QDomElement element, QString searchElementName, QList<QString> value) {

}

QDomElement XmlUtils::readSingleNode(QDomElement element, QString searchElementName) {
    //Взять список всех дочерних, входящих в неё нод
    QDomNodeList childs= element.childNodes();
    for (int i = 0; i < childs.size() ; i++) {
        //Перебираем по 1 входящий в 'Database элемент ноде
        QDomNode domNode = childs.at(i);

        //Если нода это элемент вообще (может быть комментарий или кракозябра
        if (!domNode.isElement()) {
            throw std::runtime_error(QString("[XmlUtils] Error reading QDomElement from file!").toLocal8Bit().constData());
        }

        //Так как это элемент, можно ноду для поиска скастовать в элемент для работы
        QDomElement domElement = domNode.toElement();

        //на всякий случай, проверяем, что он нормально скастовался
        if (domElement.isNull()) {
            throw std::runtime_error(QString("[XmlUtils] Error converting QDomNode to QDomElement!").toLocal8Bit().constData());
        }

        //Если элемент входяший в element это searchElementName, то читаем его как корневую группу
        QString nodeName = domElement.nodeName();
        if (domElement.nodeName() == searchElementName) {
            return domElement;
        }

    }

    throw std::runtime_error(QString("[XmlUtils] Error Cannot find QDomElement!").toLocal8Bit().constData());
}

QList<QDomElement> XmlUtils::readMultiNode(QDomElement element, QString searchElementName) {
    QList<QDomElement> elements;
    //Взять список всех дочерних, входящих в неё нод
    QDomNodeList childs= element.childNodes();
    for (int i = 0; i < childs.size() ; i++) {
        //Перебираем по 1 входящий в 'Database элемент ноде
        QDomNode domNode = childs.at(i);

        //Если нода это элемент вообще (может быть комментарий или кракозябра
        if (!domNode.isElement()) {
            throw std::runtime_error(QString("[XmlUtils] Error reading QDomElement from file!").toLocal8Bit().constData());
        }

        //Так как это элемент, можно ноду для поиска скастовать в элемент для работы
        QDomElement domElement = domNode.toElement();

        //на всякий случай, проверяем, что он нормально скастовался
        if (domElement.isNull()) {
            throw std::runtime_error(QString("[XmlUtils] Error converting QDomNode to QDomElement!").toLocal8Bit().constData());
        }

        //Если элемент входяший в element это searchElementName, то читаем его как корневую группу
        if (domElement.nodeName() == searchElementName) {
            elements.append(domElement);
        }

    }

    return elements;
}
