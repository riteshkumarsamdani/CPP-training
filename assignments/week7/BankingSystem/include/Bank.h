#include "User.h"
#include "Admin.h"
#include <vector>
#ifndef BANK_H
#define BANK_H

class Bank
{
    private:
        std::vector<User*> users;
        Admin* admin;
    public:
        void setAdmin(Admin* ad);
        Admin* getAdmin();
        User* getUser(std::string userId, std::string password);
        std::vector<User*>& getAllUser();
};

#endif
