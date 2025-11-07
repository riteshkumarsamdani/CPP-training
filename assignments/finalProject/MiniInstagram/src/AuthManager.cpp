#include <algorithm>
#include "AuthManager.h"
#include "User.h"

AuthManager::AuthManager(std::vector<IUser*> users) : users(users), currentUser(nullptr) {}

AuthManager::~AuthManager()
{
    for (auto user : users)
    {
        delete user;
    }
}

AuthResult AuthManager::signUp(const std::string& username, const std::string& password)
{
    AuthResult result;
    if (username.empty() || password.empty())
    {
        result = {false, AuthError::EmptyFields};
    }
    else if (getUserByUsername(username))
    {
        result = {false, AuthError::UserExists};
    }
    else
    {
        IUser* newUser = new User(username, password);
        users.push_back(newUser);
        result = {true, AuthError::None};
    }
    return result;
}

AuthResult AuthManager::signIn(const std::string& username, const std::string& password)
{
    IUser* user = getUserByUsername(username);
    AuthResult result;
    if (!user)
    {
        result = {false, AuthError::UserNotFound};
    }
    else if (user->getPassword() != password)
    {
        result = {false, AuthError::InvalidPassword};
    }
    else
    {
        currentUser = user;
        result = {true, AuthError::None};
    }
    return result;
}

void AuthManager::signOut()
{
    currentUser = nullptr;
}

bool AuthManager::deleteUser(const std::string& username)
{
    bool isDeleted = false;
    auto iterator = users.begin();
    while (iterator != users.end())
    {
        IUser* user = *iterator;
        if (user->getUsername() == username)
        {
            if (user == currentUser)
            {
                currentUser = nullptr;
            }
            delete user;
            iterator = users.erase(iterator);
            isDeleted = true;
            break;
        }
        else
        {
            ++iterator;
        }
    }
    return isDeleted;
}


std::vector<IUser*> AuthManager::getAllUsers()
{
    return users;
}

IUser* AuthManager::getCurrentUser()
{
    return currentUser;
}

bool AuthManager::isLoggedIn()
{
    return currentUser != nullptr;
}

IUser* AuthManager::getUserByUsername(const std::string& username)
{
    IUser* userFound = nullptr;
    for (auto user : users)
    {
        if (user->getUsername() == username)
            userFound = user;
    }
    return userFound;
}
