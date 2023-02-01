//
// Created by huixi on 25/1/2023.
//

#ifndef ASG_POST_H
#define ASG_POST_H

#include <string>
#include "User.h"

typedef std::string TitleType;
typedef std::string TextType;

class Post {
    TitleType postTitle;
    TextType text;
    Post *next;
    User *author;
public:

    const TitleType &getTitle() const {
        return postTitle;
    }
    void setTitle(const TitleType &postTitle) {
        Post::postTitle = postTitle;
    }

    const TextType &getText() const {
        return text;
    }

    void setText(const TextType &text) {
        Post::text = text;
    }

    Post *getNext() const {
        return next;
    }

    void setNext(Post *next) {
        Post::next = next;
    }

    User *getAuthor() const {
        return author;
    }

    void setAuthor(User *author) {
        Post::author = author;
    }

};


#endif //ASG_POST_H
