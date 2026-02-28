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
    bool loggedIn = false;
    static int accountCounter;
public:
    Admin(std::string id, std::string pass);
    bool login(std::string id, std::string pass);
    void logout();
    bool isLoggedIn() const;
    std::string getAdminId() const;
    void showAdminMenu(std::vector<User*>& users);
    User* createUser(std::string userId, std::string password , double r);
    void findUserById(std::vector<User*>& users);
    void showAllUser(std::vector<User*>& users);
    void deleteUser(std::vector<User*>& users);
    void updateUserBalance(std::vector<User*>& users);
    double totalAmount(std::vector<User*>& users);
    void createNewUser(std::vector<User*>& users);
};

#endif
