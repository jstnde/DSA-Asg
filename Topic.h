//
// Created by huixi on 20/1/2023.
//

#ifndef ASG_TOPIC_H
#define ASG_TOPIC_H

#include <string>

struct Topic {
    std::string title;
    Topic *leftNode;
    Topic *rightNode;
};

#endif //ASG_TOPIC_H
