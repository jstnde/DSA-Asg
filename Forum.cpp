//
// Created by huixi on 20/1/2023.
//

#include <iostream>
#include <utility>
#include "Forum.h"

Forum::Forum() {
    root = nullptr;
}

void Forum::insert(std::string t) {
    insert(root, std::move(t));
}

void Forum::insert(Topic *&node, std::string t) {
    if (node == nullptr) {
        Topic *newNode = new Topic;
        newNode->title = t;
        newNode->leftNode = nullptr;
        newNode->rightNode = nullptr;

        node = newNode;
    }
    else {
        for (int i = 0; i < t.length(); i++) {
            if (t[i] < node->title[i]) {
                insert(node->leftNode, t);
            }
            else if (t[i] == node->title[i]) {
                continue;
            }
            else {
                insert(node->rightNode, t);
            }
        }
    }
    std::cout << balanceFactor(node) << std::endl;

    Topic *temp = node;
    switch (balanceFactor(node)) {
        case -2:
            if (balanceFactor(node->rightNode) == 1) {
                rightRotate(node->rightNode);
            }
            std::cout << "right heavy,, left rotation" << std::endl;
            leftRotate(node);
            break;
        case 2:
            if (balanceFactor(node->leftNode) == -1) {
                leftRotate(node->leftNode);
            }
            std::cout << "left heavy,, right rotation" << std::endl;
            rightRotate(node);
            break;
        default:
            break;
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

void Forum::inOrder(Topic *t) {
    if (t != nullptr) {
        inOrder(t->leftNode);
        std::cout << t->title << std::endl;
        inOrder(t->rightNode);
    }
}

bool Forum::isEmpty() {
    return (root == nullptr);
}

int Forum::getHeight() {
    return getHeight(root);
}

int Forum::getHeight(Topic* node) {
    if (node == nullptr) return 0;

    int left = getHeight(node->leftNode);
    int right = getHeight(node->rightNode);

    return 1 + (left > right ? left : right);
}

int Forum::balanceFactor(Topic* node) {
    if (node == nullptr) return 0;

    return getHeight(node->leftNode) - getHeight(node->rightNode);
}

void Forum::leftRotate(Topic *&rt) {
    Topic *r = rt->rightNode;
    Topic *rl = r->leftNode;

    r->leftNode = rt;
    rt->rightNode = rl;
    rt = r;
}

void Forum::rightRotate(Topic *&rt) {
    Topic *l = rt->leftNode;
    Topic *lr = l->rightNode;

    l->rightNode = rt;
    rt->leftNode = lr;
    rt = l;
}