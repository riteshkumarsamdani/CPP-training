#include <iostream>
#include <string>
#include "User.h"

User::User(std::string userId, std::string password, Account* account)
{
    this -> userId = userId;
    this -> password = password;
    this -> account = account;
}

Account* User::getAccount()
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
