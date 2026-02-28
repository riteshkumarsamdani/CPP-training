#include <iostream>
#include "Admin.h"
#include "InputValidator.h"
#include "User.h"

int Admin::accountCounter = 1;

User* Admin::createUser(std::string userId, std::string password, double amount)
{
    Account* account = new Account(amount, accountCounter);
    accountCounter++;
    User* user = new User(userId, password, account);
    return user;
}

Admin::Admin(std::string id, std::string pass) : adminId(id), adminPassword(pass) {}

bool Admin::login(std::string id, std::string password) {
    if (id == adminId && password == adminPassword) {
        loggedIn = true;
        std::cout << "Admin " << adminId << " logged in successfully.\n";
        return true;
    }
    return false;
}

void Admin::logout() {
    loggedIn = false;
    std::cout << "Admin " << adminId << " logged out.\n";
}

bool Admin::isLoggedIn() const {
    return loggedIn;
}

std::string Admin::getAdminId() const {
    return adminId;
}

void Admin::showAllUser(std::vector<User*>& users)
{
    int iterator = 0;
    while(iterator < users.size())
    {
        User* user = users[iterator];
        std::cout << "User ID: " << user -> getUserId();
        std::cout << ", Account No: " << user -> getAccount() -> getAccountNumber();
        std::cout << ", Balance: " << user -> getAccount() -> getBalance() << "\n";
        iterator++;
    }
}

void Admin::findUserById(std::vector<User*>& users)
{
    std::string userId;
    std::cout << "Enter User ID: ";
    userId = userIdInput();
    bool found = false;
    int iterator = 0;
    while(iterator < users.size())
    {
        User* user = users[iterator];
        if (user -> getUserId() == userId) 
        {
            std::cout << "Found: Account No: " << user -> getAccount() -> getAccountNumber();
            std::cout << ", Balance: " << user -> getAccount() -> getBalance() << "\n";
            found = true;
            break;
        }
        iterator++;
    }
    if (!found) std::cout << "User not found.\n";
}

void Admin::deleteUser(std::vector<User*>& users)
{
    std::string userId;
    std::cout << "Enter User ID to delete: ";
    userId = userIdInput();
    bool deleted = false;
    int iterator = 0;
    while(iterator < users.size())
    {
        User* user = users[iterator];
        if(user -> getUserId() == userId)
        {
            delete user -> getAccount();
            delete user;
            users.erase(users.begin() + iterator);
            std::cout << "User deleted.\n";
            deleted = true;
            break;
        }
        iterator++;
    }
    if (!deleted) std::cout << "User not found.\n";
}

void Admin::updateUserBalance(std::vector<User*>& users)
{
    std::string uid;
    double newBalance;
    std::cout << "Enter User ID: ";
    std::cin >> uid;
    bool updated = false;
    int iterator = 0;
    while(iterator < users.size())
    {
        User* user = users[iterator];
        if (user->getUserId() == uid) 
        {
            std::cout << "Enter new balance: ";
            newBalance = getAmount();
            user -> getAccount() -> setBalance(newBalance);
            std::cout << "Balance updated.\n";
            updated = true;
            break;
        }
        iterator++;
    }
    if (!updated) std::cout << "User not found.\n";
}

double Admin::totalAmount(std::vector<User*>& users)
{
    double totalBalance = 0;
    int iterator = 0;
    while(iterator < users.size())
    {
        User* user = users[iterator];
        totalBalance += user -> getAccount() -> getBalance();
        iterator++;
    }
    return totalBalance;
}

void Admin::createNewUser(std::vector<User*>& users)
{
    std::string userId;
    std::string password;
    double balance;
    std::cout << "Enter user ID:\n";
    userId = userIdInput();
    std::cout << "Enter password:\n";
    password = userPasswordInput();
    std::cout << "Enter initial balance:\n";
    balance = getAmount();
    int iterator = 0;
    bool userExist = false;
    while(iterator < users.size())
    {
        User* user = users[iterator];
        if(user -> getUserId() == userId)
        {
            std::cout << "user exists!\n";
            userExist = true;
            break;
        }
        iterator++;
    }
    if(!userExist)
    {
        User* user = createUser(userId, password, balance);
        users.push_back(user);
        std::cout << "User created successfully!\n";
    }
}

void Admin::showAdminMenu(std::vector<User*>& users) {
    char adminChoice;
    bool active = true;

    while (active) {
        std::cout << "\n--- Admin Menu ---\n";
        std::cout << "1. Show All Users\n";
        std::cout << "2. Find User by ID\n";
        std::cout << "3. Create new user\n";
        std::cout << "4. Delete User\n";
        std::cout << "5. Update User Balance\n";
        std::cout << "6. View Total Bank Balance\n";
        std::cout << "7. Logout\n";
        std::cout << "Enter your choice: ";
        adminChoice = userInputChoice();

        switch (adminChoice) {
            case 1:
                showAllUser(users);
                break;
            case 2:
                findUserById(users);
                break;
            case 3:
                createNewUser(users);
                break;
            case 4:
                deleteUser(users);
                break;
            case 5:
                updateUserBalance(users);
                break;
            case 6:
            {
                double total = totalAmount(users);
                std::cout << "Total Bank Balance: " << total << "\n";
                break;
            }
            case 7:
            {
                logout();
                active = false;
                break;
            }
            default:
                std::cout << "Invalid choice.\n";
        }
    }
}
