#include <string>
#include "IAccount.h"
#ifndef USER_H
#define USER_H

class User
{
    private:
        std::string userId;
        std::string password;
        IAccount* account;

    public:
        User(std::string id, std::string pass, IAccount* ac);
        IAccount* getAccount();
        std::string getPassword();
        std::string getUserId();
}; 

#endif
