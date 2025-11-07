#ifndef POST_MANAGER_H
#define POST_MANAGER_H

#include "IPostManager.h"
#include "IPostRepository.h"
#include "IUserRepository.h"

class PostManager : public IPostManager
{
    private:
        std::vector<IPost*> posts;

    public:
        PostManager(std::vector<IPost*> posts);
        ~PostManager();
        IPost* getPostById(const std::string& postId) override;
        PostResult createPost(const std::string& userId, const std::string& content) override;
        PostResult deletePost(const std::string& postId, const std::string& requestingUserId) override;
        int deletePostsByUser(const std::string& userId) override;
        std::vector<IPost*> getAllPosts() override;
        std::vector<IPost*> getPostsByUser(const std::string& userId) override;
        PostResult likePost(const std::string& postId, const std::string& username) override;
        PostResult unlikePost(const std::string& postId, const std::string& username) override;
        int getLikeCount(const std::string& postId) override;
        std::vector<std::string> getUsersWhoLiked(const std::string& postId) override;
};

#endif
