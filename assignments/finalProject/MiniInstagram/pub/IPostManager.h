#ifndef IPOST_MANAGER_H
#define IPOST_MANAGER_H

#include "IPost.h"
#include <vector>
#include <string>

enum class PostError
{
    None,
    EmptyContent,
    NotFound,
    Unauthorized,
    AlreadyLiked,
    NotLiked
};

struct PostResult
{
    bool success;
    PostError error;
};

class IPostManager
{
    public:
        virtual ~IPostManager() {}
        virtual PostResult createPost(const std::string& userId, const std::string& content) = 0;
        virtual PostResult deletePost(const std::string& postId, const std::string& requestingUserId) = 0;
        virtual int deletePostsByUser(const std::string& userId) = 0;
        virtual std::vector<IPost*> getAllPosts() = 0;
        virtual std::vector<IPost*> getPostsByUser(const std::string& userId) = 0;
        virtual IPost* getPostById(const std::string& postId) = 0;
        virtual PostResult likePost(const std::string& postId, const std::string& username) = 0;
        virtual PostResult unlikePost(const std::string& postId, const std::string& username) = 0;
        virtual int getPostLikeCount(const std::string& postId) = 0;
        virtual std::vector<std::string> getUsersWhoLiked(const std::string& postId) = 0;
};

#endif
