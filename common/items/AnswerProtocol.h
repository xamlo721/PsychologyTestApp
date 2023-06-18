#ifndef LIRIPROTOCOL_H
#define LIRIPROTOCOL_H

#include <QString>
#include <QList>
#include <QPair>

class AnswerProtocol {

    public:
        int resultID;
        QPair<QList<QString>, QList<QString>> answers;

        AnswerProtocol() {

        }

        AnswerProtocol(int resultID,QPair<QList<QString>, QList<QString>> answers ) {
            this->resultID = resultID;
            this->answers = answers;

        }


        AnswerProtocol (const AnswerProtocol & other) :
            resultID(other.resultID), answers(other.answers) {

        }

        AnswerProtocol& operator=(const AnswerProtocol& other) {
            if (&other == this) {
                return *this;
            }

            this->resultID = other.resultID;
            this->answers = other.answers;

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
