//
// Created by huixi on 20/1/2023.
//

#include <iostream>
#include "Forum.h"

Forum::Forum() {

}

void Forum::insert(std::string t) {
        return insert(root, t);
}

void Forum::insert(Topic *node, std::string t) {
    if (node == nullptr) {
        Topic *newNode = new Topic;
        newNode->title = t;
        newNode->leftNode = nullptr;
        newNode->rightNode = nullptr;
        node = newNode;
    }
    else {
        for(int i = 0; i < t.length(); i++) {
            if (t[i] < node->title[i]) {
                insert(node->leftNode, t);
            }
            else if (t[i] == node->title[i]) {
                continue;
            }
            else {
                insert(node->rightNode,t);
            }
        }
    }

}

void Forum::inOrder() {
    if (isEmpty()) {
        std::cout << "No topics found" << std::endl;
    }
    else {
        inOrder(root);
    }
}

void Forum::inOrder(Topic *t) {\
    //TODO: Currently prints all titles, should add to an array
    if (t != NULL) {
        inOrder(t->leftNode);
        std::cout << t->title << std::endl;
        inOrder(t->rightNode);
    }
}

bool Forum::isEmpty() {
    return (root == nullptr);
}

