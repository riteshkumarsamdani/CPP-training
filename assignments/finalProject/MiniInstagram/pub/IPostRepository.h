#ifndef IPOST_REPOSITORY_H
#define IPOST_REPOSITORY_H

#include "IPost.h"
#include <vector>
#include <string>

class IPostRepository
{
    public:
        virtual ~IPostRepository() {}
        virtual std::vector<IPost*> getAllPosts() = 0;
        virtual bool savePosts(const std::vector<IPost*>& posts) = 0;
};

#endif
