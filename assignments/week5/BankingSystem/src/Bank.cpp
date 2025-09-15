#include <iostream>
#include "Bank.h"
#include "InputValidator.h"

void Bank::setAdmin(Admin* admin)
{
    this->admin = admin;
}

void Bank::createNewUser(std::string userId, std::string password, double balance)
{
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
        User* user = admin -> createUser(userId, password, balance);
        users.push_back(user);
        std::cout << "User created successfully!\n";
    }
}

std::vector<User*>& Bank::getAllUser()
{
    return users;
}

User* Bank::getUser(std::string userId, std::string password)
{
    User* user = nullptr;
    int iterator = 0;
    while(iterator < users.size())
    {
        if(users[iterator] -> getUserId() == userId && users[iterator] -> getPassword() == password)
        {
            user = users[iterator];
            break;
        }
        else if (users[iterator] -> getUserId() == userId)
        {
            std::cout << "wrong Password\n";
            break;
        }
        else if (iterator == users.size() - 1)
        {
            std::cout << "no user found!!\n";
        }
        iterator++;
    }
    return user;
}

void Bank::userMenu(User* currentUser)
{
    char userChoice;
    bool sessionActive = true;
    while (sessionActive) {
        std::cout << "\nWelcome, " << currentUser->getUserId() << "!\n";
        std::cout << "1. View Account Info\n";
        std::cout << "2. Transact\n";
        std::cout << "3. Show all transaction\n";
        std::cout << "4. show mini statement\n";
        std::cout << "5. Logout\n";
        userChoice = userInputChoice();
        switch (userChoice) {
            case 1:
                std::cout << "Account Number: " << currentUser->getAccount()->getAccountNumber() << "\n";
                std::cout << "Balance: " << currentUser->getAccount()->getBalance() << "\n";
                break;
            case 2:
                currentUser->getAccount()->transact();
                break;
            case 3:
                currentUser->getAccount()->showAllTransaction();
                break;
            case 4:
                currentUser->getAccount()->showMiniStatement();
                break;
            case 5:
                logoutUser();
                sessionActive = false;
                break;
            default:
                std::cout << "Invalid option!\n";
        }
    }
}

void Bank::handleOldUser()
{
    std::string userId, password;
    std::cout << "Enter user ID:\n";
    userId = userIdInput();
    std::cout << "Enter password:\n";
    password = userPasswordInput();
    currentUser = getUser(userId, password);
    if (currentUser)
    {
        userMenu(currentUser);
    }
}

void Bank::handleNewUser()
{
    std::string userId, password;
    double balance;
    std::cout << "Enter user ID:\n";
    userId = userIdInput();
    std::cout << "Enter password:\n";
    password = userPasswordInput();
    std::cout << "Enter initial balance:\n";
    balance = getAmount();
    createNewUser(userId, password, balance);
}

void Bank::logoutUser()
{
    if (currentUser) {
        std::cout << "User " << currentUser->getUserId() << " logged out.\n";
        currentUser = nullptr;
    } else {
        std::cout << "No user is currently logged in.\n";
    }
}
