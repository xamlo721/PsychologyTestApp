#ifndef ABSTRACTTEXTELEMENT_H
#define ABSTRACTTEXTELEMENT_H

#include "api/ITextElement.h"

class AbstractTextElement : public ITextElement {

    public:

        QString getText() override;

        bool hasPicture() override;

        QString getPicturePath() override;

    protected:

        QString text;

        QString picturePath;

        bool hasImage;
};

#endif // ABSTRACTTEXTELEMENT_H
