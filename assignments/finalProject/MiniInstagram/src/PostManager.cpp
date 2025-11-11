#include "PostManager.h"
#include "Post.h"
#include <algorithm>

PostManager::PostManager(std::vector<IPost*> posts) : posts(posts) {}

PostManager::~PostManager()
{
    for (auto post : posts)
    {
        delete post;
    }
}

PostResult PostManager::createPost(const std::string& userId, const std::string& content)
{
    PostResult result;
    if (content.empty())
    {
        result = {false, PostError::EmptyContent};
    }
    else
    {
        IPost* newPost = new Post(userId, content);
        posts.push_back(newPost);
        result = {true, PostError::None};
    }
    return result;
}

PostResult PostManager::deletePost(const std::string& postId, const std::string& requestingUserId)
{
    PostResult result = {false, PostError::NotFound};
    for (auto iterator = posts.begin(); iterator != posts.end(); ++iterator)
    {
        IPost* post = *iterator;
        if (post->getPostId() == postId)
        {
            if (post->getUserId() != requestingUserId)
            {
                result = {false, PostError::Unauthorized};
            }
            else
            {
                delete post;
                posts.erase(iterator);
                result = {true, PostError::None};
            }
            break;
        }
    }
    return result;
}

int PostManager::deletePostsByUser(const std::string& userId)
{
    int count = 0;
    auto iterator = posts.begin();
    while (iterator != posts.end())
    {
        IPost* post = *iterator;
        if (post->getUserId() == userId)
        {
            delete post;
            iterator = posts.erase(iterator);
            ++count;
        }
        else 
        {
            ++iterator;
        }
    }
    return count;
}


std::vector<IPost*> PostManager::getAllPosts()
{
    return posts;
}

std::vector<IPost*> PostManager::getPostsByUser(const std::string& userId)
{
    std::vector<IPost*> userPosts;
    for (auto post : posts)
    {
        if (post->getUserId() == userId)
        {
            userPosts.push_back(post);
        }
    }
    return userPosts;
}

PostResult PostManager::likePost(const std::string& postId, const std::string& username)
{
    PostResult result;
    IPost* post = getPostById(postId);
    if (!post)
    {
        result = {false, PostError::NotFound};
    }
    else if (post->addLike(username))
    {
        result = {true, PostError::None};
    }
    else
    {
        result = {false, PostError::AlreadyLiked};
    }
    return result;
}

PostResult PostManager::unlikePost(const std::string& postId, const std::string& username)
{
    PostResult result;
    IPost* post = getPostById(postId);
    if (!post)
    {
        result = {false, PostError::NotFound};
    }
    else if (!post->removeLike(username))
    {
        result = {false, PostError::NotLiked};
    }
    else
    {
        result = {true, PostError::None};
    }
    return result;
}

int PostManager::getPostLikeCount(const std::string& postId)
{
    IPost* post = getPostById(postId);
    return post ? post->getLikeCount() : 0;
}

std::vector<std::string> PostManager::getUsersWhoLiked(const std::string& postId)
{
    IPost* post = getPostById(postId);
    return post ? post->getLikedByUsers() : std::vector<std::string>{};
}

IPost* PostManager::getPostById(const std::string& postId)
{
    auto it = std::find_if(posts.begin(), posts.end(), [&](IPost* post) {
        return post->getPostId() == postId;
    });
    return it != posts.end() ? *it : nullptr;
}
