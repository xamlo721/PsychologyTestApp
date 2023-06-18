#ifndef LIRIRESULT_H
#define LIRIRESULT_H

#include "common/items/UserAccount.h"

class LiriResult {

    public:
        int resultID;
        UserAccount user;
        int st1;
        int st2;
        int st3;
        int st4;
        int st5;
        int st6;
        int st7;
        int st8;

        LiriResult() {

        }

        LiriResult(int resultID, UserAccount user, int st1, int st2,int st3,int st4,int st5,int st6,int st7,int st8) {
            this->resultID = resultID;
            this->user = user;
            this->st1 =st1;
            this->st2 =st2;
            this->st3 =st3;
            this->st4 =st4;
            this->st5 =st5;
            this->st6 =st6;
            this->st7 =st7;
            this->st8 =st8;
        }

};

#endif // LIRIRESULT_H
