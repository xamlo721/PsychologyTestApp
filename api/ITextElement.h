#ifndef ITEXTELEMENT_H
#define ITEXTELEMENT_H

#include <QString>

class ITextElement {

    public:

        virtual QString getText() = 0;

        virtual bool hasPicture() = 0;

        virtual QString getPicturePath() = 0;

};

#endif // ITEXTELEMENT_H
