#include <iostream>
#include "Bank.h"
#include "InputHandler.h"

void Bank::setAdmin(Admin* admin)
{
    this->admin = admin;
}

std::vector<User*>& Bank::getAllUser()
{
    return users;
}

User* Bank::getUser(std::string userId, std::string password)
{
    User* user = nullptr;
    int iterator = 0;
    while(iterator < users.size())
    {
        if(users[iterator] -> getUserId() == userId && users[iterator] -> getPassword() == password)
        {
            user = users[iterator];
            break;
        }
        else if (users[iterator] -> getUserId() == userId)
        {
            std::cout << "wrong Password\n";
            break;
        }
        else if (iterator == users.size() - 1)
        {
            std::cout << "no user found!!\n";
        }
        iterator++;
    }
    return user;
}

Admin* Bank::getAdmin()
{
    return admin;
}
