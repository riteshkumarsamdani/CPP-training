#include <string>
#include "Account.h"
#include "User.h"
#ifndef ADMIN_H
#define ADMIN_H

class Admin
{
    private:
        std::string adminId;
        std::string adminPassword;
        static int accountCounter;
    public:
        Admin(std::string id, std::string pass);
        std::string getAdminId() const;
        std::string getAdminPassword() const;
        User* findUser(std::vector<User*>& users, const std::string& userId);
        bool findUserById(std::vector<User*>& users);
        void showAllUser(std::vector<User*>& users);
        bool deleteUser(std::vector<User*>& users);
        bool updateUserBalance(std::vector<User*>& users);
        bool createNewUser(std::vector<User*>& users);
};

#endif
