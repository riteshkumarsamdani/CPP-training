#include "User.h"

User::User(std::string username, std::string password) : username(username), password(password)
{
    userId = generateUserId(username);
}

User::User(std::string userId, std::string username, std::string password)
    : userId(userId), username(username), password(password) {}

std::string User::generateUserId(std::string username)
{
    return "U" + std::to_string(time(nullptr)) + username.substr(0, 2);
}

std::string User::getUserId() const
{
    return userId;
}

std::string User::getUsername() const
{
    return username;
}

std::string User::getPassword() const
{
    return password;
}
