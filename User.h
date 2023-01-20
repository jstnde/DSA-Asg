//
// Created by Justin Chan on 20/1/2023.
//

#ifndef ASG_USER_H
#define ASG_USER_H

#include <string>

typedef std::string UsernameType;
typedef std::string PasswordType;

struct User {
    UsernameType username;
    PasswordType password;
    User *next;
};

#endif //ASG_USER_H
