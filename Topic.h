//
// Created by huixi on 20/1/2023.
//

#ifndef ASG_TOPIC_H
#define ASG_TOPIC_H

#include "Post.h"

class Topic {
    std::string title;
    Topic *leftNode;
    Topic *rightNode;
    Post *top;

public:
    Topic();
    ~Topic();
    bool createPost(TitleType postTitle, TextType text, User *author);
    bool deletePost(TitleType &postTitle, User *user);
    bool isEmpty();
};

#endif //ASG_TOPIC_H
