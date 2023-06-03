#ifndef ABSTRACTTEXTELEMENT_H
#define ABSTRACTTEXTELEMENT_H

#include "api/ITextElement.h"

class AbstractTextElement : public ITextElement {
    private:
        static int counter;

    public:
        AbstractTextElement() = delete;
        AbstractTextElement(QString text, bool hasImage = false, QString imagePath = "");


        virtual QString getText() override;

        virtual bool hasPicture() override;

        virtual QString getPicturePath() override;

        AbstractTextElement& operator=(const AbstractTextElement& other);
        virtual bool operator==(const AbstractTextElement& other) const;
        virtual bool operator!=(const AbstractTextElement& other) const;
        virtual bool operator<(const AbstractTextElement& other) const;
        virtual bool operator>(const AbstractTextElement& other) const;

    protected:

        QString text;

        QString picturePath;

        bool hasImage;

        int id;
};

#endif // ABSTRACTTEXTELEMENT_H
