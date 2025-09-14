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
        User* currentUser = nullptr;
    public:
        void setAdmin(Admin* ad);
        void createNewUser(std::string userId, std::string password, double balance);
        User* getUser(std::string userId, std::string password);
        std::vector<User*>& getAllUser();
        void handleNewUser();
        void handleOldUser();
        void logoutUser();
        void userMenu(User* currentUser);
};

#endif
