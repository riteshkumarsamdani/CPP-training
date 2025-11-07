#include "PostRepository.h"
#include "Post.h"
#include <fstream>
#include <iostream>

PostRepository::PostRepository(std::string filePath) : filePath(filePath)
{
    initializeFile();
}

void PostRepository::initializeFile()
{
    std::ifstream file(filePath);
    if (!file.good())
    {
        std::ofstream newFile(filePath);
        nlohmann::json emptyArray = nlohmann::json::array();
        newFile << emptyArray.dump(2);
        newFile.close();
    }
}

std::vector<IPost*> PostRepository::getAllPosts()
{
    std::vector<IPost*> posts;
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        std::cerr << "Failed to open file for reading: " << filePath << std::endl;
    }
    else
    {
        try
        {
            nlohmann::json jsonData;
            file >> jsonData;
            file.close();
            for (const auto& item : jsonData)
            {
                std::string postId = item.value("postId", "");
                std::string userId = item.value("userId", "");
                std::string content = item.value("content", "");
                std::string timestamp = item.value("timestamp", "");
                std::vector<std::string> likedByUsers;
                if (item.contains("likedByUsers") && item["likedByUsers"].is_array())
                {
                    for (const auto& like : item["likedByUsers"])
                    {
                        likedByUsers.push_back(like.get<std::string>());
                    }
                }
                if (!postId.empty())
                {
                    posts.push_back(new Post(postId, userId, content, timestamp, likedByUsers));
                }
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error loading data from File" << e.what() << '\n';
        }
    }
    return posts;
}

bool PostRepository::savePosts(const std::vector<IPost*>& posts)
{
    nlohmann::json jsonArray = nlohmann::json::array();
    bool saved = false;
    try
    {
        for (const auto& post : posts)
        {
            jsonArray.push_back({
                {"postId", post->getPostId()},
                {"userId", post->getUserId()},
                {"content", post->getContent()},
                {"timestamp", post->getTimestamp()},
                {"likedByUsers", post->getLikedByUsers()}
            });
        }
        std::ofstream file(filePath);
        if (!file.is_open())
        {
            std::cerr << "Failed to open file for writing: " << filePath << std::endl;
        }
        else
        {
            file << jsonArray.dump(2);
            file << "\n";
            file.close();
            saved = true;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error saving posts to JSON: " << e.what() << std::endl;
        saved = false;
    }
    return saved;
}
