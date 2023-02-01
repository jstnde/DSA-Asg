//
// Created by huixi on 20/1/2023.
//

#ifndef ASG_TOPIC_H
#define ASG_TOPIC_H

#include "Post.h"

class Topic {
public:
    std::string title;
    Topic *leftNode;
    Topic *rightNode;
    Post *top;

    Topic();
    ~Topic();
    bool createPost(TitleType postTitle, TextType text, User *author);
    bool deletePost(TitleType &postTitle, User *user);
    bool isEmpty();
};

#endif //ASG_TOPIC_H
