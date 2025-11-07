#ifndef USER_H
#define USER_H

#include "IUser.h"
#include <string>
#include <ctime>

class User : public IUser
{
    private:
        std::string userId;
        std::string username;
        std::string password;
        std::string generateUserId(std::string username);

    public:
        User(std::string username, std::string password);
        User(std::string userId, std::string username, std::string password);
        std::string getUserId() const override;
        std::string getUsername() const override;
        std::string getPassword() const override;
};

#endif
