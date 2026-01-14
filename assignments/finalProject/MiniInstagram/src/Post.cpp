#include "Post.h"
#include <algorithm>
#include <sstream>
#include <iomanip>

Post::Post(std::string userId, std::string content) : userId(userId), content(content)
{
    postId = generatePostId(userId);
    timestamp = getCurrentTimestamp();
}

Post::Post(std::string postId, std::string userId, std::string content, std::string timestamp, std::vector<std::string> likedByUsers)
    : postId(postId), userId(userId), content(content), timestamp(timestamp), likedByUsers(likedByUsers) {}

std::string Post::generatePostId(std::string userId)
{
    return "P" + std::to_string(time(nullptr)) + userId.substr(userId.length()-2);
}

std::string Post::getCurrentTimestamp()
{
    time_t now = time(nullptr);
    tm* ltm = localtime(&now);
    std::stringstream ss;
    ss << std::put_time(ltm, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

std::string Post::getPostId() const
{
    return postId;
}

std::string Post::getUserId() const
{
    return userId;
}

std::string Post::getContent() const
{
    return content;
}

std::string Post::getTimestamp() const
{
    return timestamp;
}

std::vector<std::string> Post::getLikedByUsers() const
{
    return likedByUsers;
}

bool Post::addLike(std::string username)
{
    bool liked = false;
    if(find(likedByUsers.begin(), likedByUsers.end(), username) == likedByUsers.end())
    {
        likedByUsers.push_back(username);
        liked = true;
    }
    return liked;
}

bool Post::removeLike(std::string username)
{
    auto it = find(likedByUsers.begin(), likedByUsers.end(), username);
    bool result = false;
    if (it != likedByUsers.end())
    {
        likedByUsers.erase(it);
        result = true;
    }
    return result;
}

int Post::getLikeCount() const
{
    return likedByUsers.size();
}
