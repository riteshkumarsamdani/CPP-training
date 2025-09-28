#include <iostream>
#include "Admin.h"
#include "IAccount.h"
#include "InputHandler.h"
#include "SavingAccount.h"
#include "LoanAccount.h"
#include "CurrentAccount.h"
#include "User.h"

int Admin::accountCounter = 1;

Admin::Admin(std::string id, std::string pass) : adminId(id), adminPassword(pass) {}

std::string Admin::getAdminId() const 
{
    return adminId;
}

std::string Admin::getAdminPassword() const 
{
    return adminPassword;
}

void Admin::showAllUser(std::vector<User*>& users)
{
    int iterator = 0;
    while(iterator < users.size())
    {
        User* user = users[iterator];
        std::cout << "User ID: " << user -> getUserId() << "\n";
        std::cout << user->getAccount()->getAccountSummary() << "\n";
        iterator++;
    }
}

bool Admin::findUserById(std::vector<User*>& users)
{
    std::string userId;
    getUserInput("Enter User ID: ", userId);
    bool userExist;
    User* user = findUser(users, userId);
    if (user) 
    {
        std::cout << "Found: Account No: " << user->getAccount()->getAccountNumber()
                  << ", Balance: " << user->getAccount()->getBalance() << "\n";
        userExist = true;
    } 
    else 
    {
        std::cout << "User not found.\n";
        userExist =  false;
    }
    return userExist;
}

bool Admin::deleteUser(std::vector<User*>& users)
{
    std::string userId;
    getUserInput("Enter User ID to delete: ", userId);
    bool userDeleted = false;
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
            userDeleted = true;
            break;
        }
        iterator++;
    }
    if (!userDeleted) std::cout << "User not found.\n";
    return userDeleted;
}

bool Admin::createNewUser(std::vector<User*>& users)
{
    std::string userId;
    std::string password;
    std::string accountType;
    double balance;
    bool userCreated = false;
    bool accountCreated = true;
    getUserInput("Enter user ID: ", userId);
    getUserInput("Enter password: ", password);
    getPositiveUserInput("Enter initial balance: ", balance);
    getUserInput("Enter Account Type: ", accountType);
    User* user = findUser(users,userId);
    if(!user)
    {
        IAccount* account = nullptr;
        if (accountType == "saving") account = new SavingAccount(balance, accountCounter++);
        else if (accountType == "current") account = new CurrentAccount(balance, accountCounter++);
        else if (accountType == "loan") account = new LoanAccount(balance, accountCounter++);
        else 
        {
            std::cout << "Invalid account type.\n";
            accountCreated = false;
        }
        if(accountCreated)
        {
            user = new User(userId, password, account);
            users.push_back(user);
            userCreated = true;
            std::cout << "User created successfully!\n";
        }
    }
    return userCreated;
}

User* Admin::findUser(std::vector<User*>& users, const std::string& userId)
{
    int iterator = 0;
    User* user = nullptr;
    while (iterator < users.size()) 
    {
        if (users[iterator]->getUserId() == userId) 
        {
            user = users[iterator];
            break;
        }
        iterator++;
    }
    return user;
}

bool Admin::updateUserBalance(std::vector<User*>& users)
{
    std::string userId;
    double newBalance;
    getUserInput("Enter User ID: ", userId);
    User* user = findUser(users, userId);
    bool balanceUpdated;
    if (user) 
    {
        getPositiveUserInput("Enter new balance: ", newBalance);
        user->getAccount()->setBalance(newBalance);
        std::cout << "Balance updated.\n";
        balanceUpdated = true;
    } 
    else 
    {
        std::cout << "User not found.\n";
        balanceUpdated = false;
    }
    return balanceUpdated;
}

