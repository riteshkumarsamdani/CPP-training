#include <string>
#include "Account.h"
#ifndef USER_H
#define USER_H

class User
{
    private:
        std::string userId;
        std::string password;
        Account* account;

    public:
        User(std::string id, std::string pass, Account* ac);
        Account* getAccount();
        std::string getPassword();
        std::string getUserId();
}; 

#endif
