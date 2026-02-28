#include <iostream>
#include "Bank.h"
#include "InputValidator.h"

Admin* adminLogin(std::vector<Admin*>& adminList)
{
    Admin* currentAdmin = nullptr;
    std::string userId, userPassword;
    std::cout << "Enter Admin ID: ";
    userId = userIdInput();
    std::cout << "Enter Password: ";
    userPassword = userPasswordInput();
    bool adminFound = false;
    int iterator = 0;
    while(iterator < adminList.size())
    {
        Admin* admin = adminList[iterator];
        if (admin->login(userId, userPassword)) 
        {
            currentAdmin = admin;
            adminFound = true;
            break;
        }
        iterator++;
    }
    if (!adminFound) std::cout << "Invalid admin credentials.\n";
    return currentAdmin;
}

void bankMenu(Bank* bank, std::vector<Admin*>& adminList)
{
    bool run = true;
    char userChoice;
    while (run)
    {
        std::cout << "\n--- Welcome to the Bank System ---\n";
        std::cout << "1. Register New User\n";
        std::cout << "2. Login as Existing User\n";
        std::cout << "3. Login as Admin\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        userChoice = userInputChoice();
        switch (userChoice)
        {
            case 1:
                bank -> handleNewUser();
                break;
            case 2:
                bank -> handleOldUser();
                break;
            case 3: 
            {
                Admin* admin = adminLogin(adminList);
                if(admin)
                {
                    admin -> showAdminMenu(bank -> getAllUser());
                }
                break;
            }
            case 4:
                run = false;
                std::cout << "Thank you for using the Bank System. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
                break;
        }
    }
}

int main()
{
    Bank* bank = new Bank();
    std::vector<Admin*> adminList = 
    {
        new Admin("admin1", "pass1"),
        new Admin("admin2", "pass2"),
        new Admin("admin3", "pass3"),
        new Admin("admin4", "pass4")
    };
    bank -> setAdmin(adminList[0]);
    bankMenu(bank, adminList);
    for (Admin* admin : adminList) 
    {
        delete admin;
    }
    adminList.clear();
    delete bank;
    return 0;
}
