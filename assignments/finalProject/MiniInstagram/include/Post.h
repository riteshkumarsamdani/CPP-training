#ifndef POST_H
#define POST_H

#include "IPost.h"
#include <string>
#include <vector>
#include <ctime>

class Post : public IPost
{
    private:
        std::string postId;
        std::string userId;
        std::string content;
        std::string timestamp;
        std::vector<std::string> likedByUsers;
        std::string generatePostId(std::string userId);
        std::string getCurrentTimestamp();

    public:
        Post(std::string userId, std::string content);
        Post(std::string postId, std::string userId, std::string content, std::string timestamp, std::vector<std::string> likedByUsers);
        std::string getPostId() const override;
        std::string getUserId() const override;
        std::string getContent() const override;
        std::string getTimestamp() const override;
        std::vector<std::string> getLikedByUsers() const override;
        bool addLike(std::string username) override;
        bool removeLike(std::string username) override;
        int getLikeCount() const override;
};

#endif
