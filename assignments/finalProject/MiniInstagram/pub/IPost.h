#ifndef IPOST_H
#define IPOST_H

#include <string>
#include <vector>

class IPost
{
    public:
        virtual ~IPost() {}
        virtual std::string getPostId() const = 0;
        virtual std::string getUserId() const = 0;
        virtual std::string getContent() const = 0;
        virtual std::string getTimestamp() const = 0;
        virtual std::vector<std::string> getLikedByUsers() const = 0;
        virtual bool addLike(std::string username) = 0;
        virtual bool removeLike(std::string username) = 0;
        virtual int getLikeCount() const = 0;
};

#endif
