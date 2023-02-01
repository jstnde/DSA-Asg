//
// Created by huixi on 20/1/2023.
//

#include <iostream>
#include "Topic.h"


Topic::Topic() {
    top = nullptr;
}

Topic::~Topic() {

}

bool Topic::createPost(TitleType title, TextType text, User *author) {
    Post *newNode = new Post;
    newNode->setTitle(title);
    newNode->setText(text);
    newNode->setNext(top);
    newNode->setAuthor(author);
    top = newNode;
    return true;
}

bool Topic::deletePost(TitleType &postTitle, User *user) {
    bool success = !isEmpty();
    if (!success) {
        return false;
    }

    Post *current = top;
    if (current->getTitle() != title) {
        while (current->getNext() != nullptr) {
            if (current->getNext()->getTitle() == title) {
                break;
            }
            current = current->getNext();
        }
    }

    if (user == current->getAuthor()) {
        std::cout << "User has been validated" << std::endl;
    }
}

bool Topic::isEmpty() {
    if (top == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

