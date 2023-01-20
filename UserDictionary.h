//
// Created by Justin Chan on 20/1/2023.
//

#ifndef ASG_USERDICTIONARY_H
#define ASG_USERDICTIONARY_H


#include <string>
#include <cmath>
#include "User.h"

const int MAX_SIZE = 211;

class UserDictionary {
    User *users[MAX_SIZE];
    int size;

    static int charvalue(char c) {
        if (isalpha(c)) {
            if (isupper(c))
                return (int)c - (int) 'A';
            else
                return (int)c - (int) 'a' + 26;
        }
        else
            return -1;
    }

public:
    UserDictionary();

    virtual ~UserDictionary();

    int hash(UsernameType username);

    bool add(const UsernameType& username, const PasswordType& password);

    void remove(const UsernameType& username);

    User* getUser(const UsernameType& username);

    bool isEmpty() const;

    int getLength() const;

    void print();

    void replace(UsernameType username, PasswordType password);

    bool contains(UsernameType username);
};


#endif //ASG_USERDICTIONARY_H
