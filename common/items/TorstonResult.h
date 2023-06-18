#ifndef TORSTONRESULT_H
#define TORSTONRESULT_H

#include <QString>
#include "common/items/EnumTorsonResult.h"
#include "common/items/UserAccount.h"

class TorstonResult {

    public:
        int resultID;
        UserAccount user;
        EnumTorsonResult result;

        TorstonResult() {

        }

        TorstonResult(int resultID, UserAccount user, EnumTorsonResult result) {
            this->resultID = resultID;
            this->user = user;
            this->result = result;
        }


        TorstonResult (const TorstonResult & other) :
            resultID(other.resultID), user(other.user),
            result(other.result){

        }

        TorstonResult& operator=(const TorstonResult& other) {
            if (&other == this) {
                return *this;
            }

            this->resultID = other.resultID;
            this->user = other.user;
            this->result = other.result;

            return *this;
        }

        bool operator==(const TorstonResult& other) const {
            return (resultID == other.resultID &&
                    user == other.user);
        }

        bool operator!=(const TorstonResult& other) const {
            return !(*this == other);
        }

        bool operator<(const TorstonResult& other) const {
            return this->resultID < other.resultID;
        }

        bool operator>(const TorstonResult& other) const {
            return !(*this < other);
        }

};

#endif // TORSTONRESULT_H
