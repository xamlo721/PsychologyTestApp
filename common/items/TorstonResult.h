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


};

#endif // TORSTONRESULT_H
