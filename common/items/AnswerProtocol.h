#ifndef LIRIPROTOCOL_H
#define LIRIPROTOCOL_H

#include <QString>
#include <QList>
#include <QPair>
#include "common/items/UserAccount.h"

class AnswerProtocol {

    public:
        int resultID;
        UserAccount user;
        QPair<QList<QString>, QList<QString>> answers;

        AnswerProtocol() {

        }

        AnswerProtocol(int resultID, UserAccount user, QPair<QList<QString>, QList<QString>> answers ) {
            this->resultID = resultID;
            this->user = user;
            this->answers = answers;

        }


        AnswerProtocol (const AnswerProtocol & other) :
            resultID(other.resultID), answers(other.answers), user(other.user) {

        }

        AnswerProtocol& operator=(const AnswerProtocol& other) {
            if (&other == this) {
                return *this;
            }

            this->resultID = other.resultID;
            this->answers = other.answers;
            this->user = other.user;

            return *this;
        }

        bool operator==(const AnswerProtocol& other) const {
            return (resultID == other.resultID &&
                    answers == other.answers);
        }

        bool operator!=(const AnswerProtocol& other) const {
            return !(*this == other);
        }

        bool operator<(const AnswerProtocol& other) const {
            return this->resultID < other.resultID;
        }

        bool operator>(const AnswerProtocol& other) const {
            return !(*this < other);
        }

};


#endif // LIRIPROTOCOL_H
