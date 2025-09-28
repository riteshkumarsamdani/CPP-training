#include <iostream>
#include "Bank.h"
#include "BankManagement.h"
#include "InputHandler.h"

void BankManagement::displayUserMenu(const std::string& userId)
{
    std::cout << "\nWelcome, " << userId << "!\n";
    std::cout << "1. View Account Info\n";
    std::cout << "2. Transact\n";
    std::cout << "3. Show all transaction\n";
    std::cout << "4. show mini statement\n";
    std::cout << "5. Logout\n";
}

void BankManagement::displayTransactions(const std::vector<std::string>& transactions)
{
    for(auto transaction:transactions)
    {
        std::cout << transaction;
    }
}

void BankManagement::userOperationHandler(User* currentUser)
{
    int userChoice;
    bool sessionActive = true;
    while (sessionActive) 
    {
        displayUserMenu(currentUser -> getUserId());
        getUserInput("Enter your choice: ", userChoice);
        switch (userChoice) 
        {
            case 1:
                std::cout << currentUser -> getAccount() -> getAccountSummary();
                break;
            case 2:
                currentUser->getAccount()->transactionHandler();
                break;
            case 3:
            {
                displayTransactions(currentUser -> getAccount() -> getTransactionHistory());
                break;
            }
            case 4:
            {
                displayTransactions(currentUser -> getAccount() -> getMiniStatement());
                break;
            }
            case 5:
            {
                std::cout << "User " << currentUser->getUserId() << " logged out.\n";
                currentUser = nullptr;
                sessionActive = false;
                break;
            }
            default:
                std::cout << "Invalid option!\n";
        }
    }
}

void BankManagement::userLogin(Bank* bank)
{
    User* currentUser = nullptr;
    std::string userId, password;
    getUserInput("Enter user ID: ", userId);
    getUserInput("Enter password: ", password);
    currentUser = bank -> getUser(userId, password);
    if (currentUser)
    {
        userOperationHandler(currentUser);
    }
}

void BankManagement::userSignUp(Bank* bank)
{
    bank -> getAdmin() -> createNewUser(bank -> getAllUser());
}

void BankManagement::displayAdminMenu()
{
    std::cout << "\n--- Admin Menu ---\n";
    std::cout << "1. Show All Users\n";
    std::cout << "2. Find User by ID\n";
    std::cout << "3. Create new user\n";
    std::cout << "4. Delete User\n";
    std::cout << "5. Update User Balance\n";
    std::cout << "6. Logout\n";
}

void BankManagement::adminOperationHandler(std::vector<User*>& users, Admin* admin) 
{
    int adminChoice;
    bool active = true;

    while (active) {
        displayAdminMenu();
        getUserInput("Enter your choice: ", adminChoice);
        switch (adminChoice) {
            case 1:
                admin -> showAllUser(users);
                break;
            case 2:
                admin -> findUserById(users);
                break;
            case 3:
                admin -> createNewUser(users);
                break;
            case 4:
                admin -> deleteUser(users);
                break;
            case 5:
                admin -> updateUserBalance(users);
                break;
            case 6:
            {
                std::cout << "Admin " << admin->getAdminId() << " logged out.\n";
                admin = nullptr;
                active = false;
                break;
            }
            default:
                std::cout << "Invalid choice.\n";
        }
    }
}

Admin* BankManagement::adminLogin(std::vector<Admin*>& adminList)
{
    Admin* currentAdmin = nullptr;
    std::string id, password;
    getUserInput("Enter Admin ID: ", id);
    getUserInput("Enter Password: ", password);
    bool adminFound = false;
    int iterator = 0;
    while(iterator < adminList.size())
    {
        Admin* admin = adminList[iterator];
        if (admin->getAdminId() == id && admin->getAdminPassword() == password) 
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

void BankManagement::displayBankMenu()
{
    std::cout << "\n--- Welcome to the Bank System ---\n";
    std::cout << "1. Register New User\n";
    std::cout << "2. Login as Existing User\n";
    std::cout << "3. Login as Admin\n";
    std::cout << "4. Exit\n";
}

void BankManagement::bankOperationHandler(Bank* bank, std::vector<Admin*>& adminList)
{
    bool run = true;
    int userChoice;
    while (run)
    {
        displayBankMenu();
        getUserInput("Enter your choice: ", userChoice);
        switch (userChoice)
        {
            case 1:
                userLogin(bank);
                break;
            case 2:
                userSignUp(bank);
                break;
            case 3: 
            {
                Admin* admin = adminLogin(adminList);
                if(admin)
                {
                    adminOperationHandler(bank -> getAllUser(), admin);
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
