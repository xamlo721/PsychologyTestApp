#ifndef TORSTONRESULT_H
#define TORSTONRESULT_H

#include <QString>
#include "common/items/EnumTorsonResult.h"

class TorstonResult {

    public:
        QString user;
        EnumTorsonResult result;

        TorstonResult() {

        }

        TorstonResult(QString user, EnumTorsonResult result) {
            this->user = user;
            this->result = result;
        }


};

#endif // TORSTONRESULT_H
