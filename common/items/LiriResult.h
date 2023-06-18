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


        LiriResult (const LiriResult & other) :
            resultID(other.resultID), user(other.user),
            st1(other.st1), st2(other.st2), st3(other.st3), st4(other.st4),
             st5(other.st5), st6(other.st6), st7(other.st7), st8(other.st8) {

        }

        LiriResult& operator=(const LiriResult& other) {
            if (&other == this) {
                return *this;
            }

            this->resultID = other.resultID;
            this->user = other.user;
            this->st1 = other.st1;
            this->st2 = other.st2;
            this->st3 = other.st3;
            this->st4 = other.st4;
            this->st5 = other.st5;
            this->st6 = other.st6;
            this->st7 = other.st7;
            this->st8 = other.st8;

            return *this;
        }

        bool operator==(const LiriResult& other) const {
            return (resultID == other.resultID &&
                    user == other.user);
        }

        bool operator!=(const LiriResult& other) const {
            return !(*this == other);
        }

        bool operator<(const LiriResult& other) const {
            return this->resultID < other.resultID;
        }

        bool operator>(const LiriResult& other) const {
            return !(*this < other);
        }

};

#endif // LIRIRESULT_H
