#include "UserRepository.h"
#include "User.h"
#include <fstream>
#include <iostream>

UserRepository::UserRepository(std::string filePath) : filePath(filePath)
{
    initializeFile();
}

void UserRepository::initializeFile()
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

std::vector<IUser*> UserRepository::getAllUsers()
{
    std::vector<IUser*> users;
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
                std::string userId = item.value("userId", "");
                std::string username = item.value("username", "");
                std::string password = item.value("password", "");
                if (!userId.empty())
                {
                    users.push_back(new User(userId, username, password));
                }
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error loading data from File:" << e.what() << '\n';
        }
    }
    return users;
}

bool UserRepository::saveUsers(const std::vector<IUser*>& users)
{
    nlohmann::json jsonArray = nlohmann::json::array();
    bool result = false;
    try
    {
        for (const auto& user : users)
        {
            nlohmann::json userJson;
            userJson["userId"] = user->getUserId();
            userJson["username"] = user->getUsername();
            userJson["password"] = user->getPassword();
            jsonArray.push_back(userJson);
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
            result = true;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error saving posts to JSON: " << e.what() << std::endl;
    }
    return result;
}
