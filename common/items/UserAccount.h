#ifndef USERACCOUNT_H
#define USERACCOUNT_H

#include <QObject>
#include <QString>

class UserAccount : public QObject {

    Q_OBJECT

    private:
        int userID;
        QString userName;

    public:
        UserAccount () {

        }

        UserAccount (int id, QString name) {
            this->userID = id;
            this->userName = name;
        }

        UserAccount (const UserAccount & other) :
            userID(other.userID), userName(other.userName) {

        }

        UserAccount& operator=(const UserAccount& other) {
            if (&other == this) {
                return *this;
            }

            this->userID = other.userID;
            this->userName = other.userName;

            return *this;
        }

        bool operator==(const UserAccount& other) const {
            return (userID == other.userID &&
                    userName == other.userName);
        }

        bool operator!=(const UserAccount& other) const {
            return !(*this == other);
        }

        bool operator<(const UserAccount& other) const {
            return this->userID < other.userID;
        }

        bool operator>(const UserAccount& other) const {
            return !(*this < other);
        }

        int getID() {
            return this->userID;
        }

        QString getName() {
            return this->userName;
        }

        void changeUserName(QString newUserName) {
            this->userName = newUserName;
        }

};

#endif // USERACCOUNT_H
