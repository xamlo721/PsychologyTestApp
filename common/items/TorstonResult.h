#ifndef TORSTONRESULT_H
#define TORSTONRESULT_H

#include <QString>
#include "common/items/EnumTorsonResult.h"
#include "common/items/UserAccount.h"

class TorstonResult {

    public:
        UserAccount user;
        EnumTorsonResult result;

        TorstonResult() {

        }

        TorstonResult(UserAccount user, EnumTorsonResult result) {
            this->user = user;
            this->result = result;
        }


};

#endif // TORSTONRESULT_H
