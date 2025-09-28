#include <iostream>
#include "Bank.h"
#include "BankManagement.h"
#include "Admin.h"

int main()
{
    BankManagement* manage = new BankManagement();
    Bank* bank = new Bank();
    std::vector<Admin*> adminList = 
    {
        new Admin("admin1", "pass1"),
        new Admin("admin2", "pass2"),
        new Admin("admin3", "pass3"),
        new Admin("admin4", "pass4")
    };
    bank -> setAdmin(adminList[0]);
    manage -> bankOperationHandler(bank, adminList);
    for (Admin* admin : adminList) 
    {
        delete admin;
    }
    adminList.clear();
    delete bank;
    return 0;
}
