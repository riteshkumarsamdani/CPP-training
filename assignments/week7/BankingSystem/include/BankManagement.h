#include "User.h"
#include "Bank.h"
#include "Admin.h"
#include <vector>
#ifndef BANK_MANAGEMENT_H
#define BANK_MANAHEMENT_H

class BankManagement
{
    public:
        void bankOperationHandler(Bank* bank, std::vector<Admin*>& adminList);
        Admin* adminLogin(std::vector<Admin*>& adminList);
        void adminOperationHandler(std::vector<User*>& users, Admin* admin);
        void userLogin(Bank* bank);
        void userSignUp(Bank* bank);
        void userOperationHandler(User* currentUser);
        void displayUserMenu(const std::string& userId);
        void displayTransactions(const std::vector<std::string>& transactions);
        void displayAdminMenu();
        void displayBankMenu();
};

#endif
