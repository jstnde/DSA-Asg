//
// Created by Justin Chan on 20/1/2023.
//

#include "UserDictionary.h"

UserDictionary::UserDictionary(): users(), size(0) {}

UserDictionary::~UserDictionary() {
    for (User *cur:users) {
        for (; cur != nullptr; cur = cur->next) {
            remove(cur->username);
        }
        if (getLength() == 0) {
            return;
        }
    }
}

int UserDictionary::hash(UsernameType username) {
    int index = 0;
    for (int i = 0; i < username.size(); i++) {
        index += charvalue(username[i]) * pow(52, username.size() - i);
    }

    return (index < 0 ? index * -1 : index) % MAX_SIZE;
}

bool UserDictionary::add(const UsernameType& username, const PasswordType& password) {
    int index = hash(username);

    if (users[index] == nullptr) {
        User *u = new User;
        u->username = username;
        u->password = password;
        u->next = nullptr;

        users[index] = u;
    }
    else {
        User *cur = users[index];
        for (; cur != nullptr; cur = cur->next) {
            if (cur->username == username) return false;
        }

        User *u = new User;
        u->username = username;
        u->password = password;
        u->next = nullptr;
        cur = u;
    }
    size++;
    return true;
}

void UserDictionary::remove(const UsernameType& username) {
    int index = hash(username);

    User *cur = users[index];
    if (cur == nullptr) return;
    else if (cur->username == username) {
        delete users[index];
        users[index] = nullptr;
        size--;
        return;
    }
    for (; cur->next != nullptr; cur = cur->next) {
        if (cur->next->username == username) {
            User *temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
            size--;
            break;
        }
    }
}

User* UserDictionary::getUser(const UsernameType& username) {
    int index = hash(username);
    PasswordType user;

    User *cur = users[index];
    for (; cur != nullptr; cur = cur->next) {
        if (cur->username == username) {
            return cur;
        }
    }
    return nullptr;
}

bool UserDictionary::isEmpty() const {
    return getLength() == 0;
}

int UserDictionary::getLength() const {
    return size;
}

void UserDictionary::print() {

}

void UserDictionary::replace(UsernameType username, PasswordType password) {

}

bool UserDictionary::contains(UsernameType username) {
    return false;
}


