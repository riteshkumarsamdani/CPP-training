#include <iostream>
#include <string>
#include "User.h"

User::User(std::string userId, std::string password, IAccount* account)
{
    this -> userId = userId;
    this -> password = password;
    this -> account = account;
}

IAccount* User::getAccount()
{
    return account;
}

std::string User::getPassword()
{
    return password;
}

std::string User::getUserId()
{
    return userId;
}
