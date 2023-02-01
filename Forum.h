//
// Created by huixi on 20/1/2023.
//

#ifndef ASG_FORUM_H
#define ASG_FORUM_H

#include "Topic.h"

class Forum {
    Topic* root;

public:
    Forum();

    void insert(std::string t);

    void insert(Topic *&node, std::string t);

    void inOrder();

    void inOrder(Topic* t);

    bool isEmpty();

    int getHeight();

    int getHeight(Topic *node);

    int balanceFactor(Topic *node);

    void leftRotate(Topic *&rt);

    void rightRotate(Topic *&rt);
};



#endif //ASG_FORUM_H
