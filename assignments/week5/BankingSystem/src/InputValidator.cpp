#include <iostream>
#include <limits>
#include "InputValidator.h"

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool validateInput()
{
    bool isValidInput = true;
    if (std::cin.eof())
    {
        exit(1);
    }
    if (std::cin.fail() || std::cin.peek() != '\n') 
    {
        std::cin.clear();
        isValidInput = false;
    }
    ignoreLine();
    return isValidInput;
}

int userInputChoice()
{
    int userChoice;
    while (true) 
    {
        std::cin >> userChoice;
        if (validateInput()) break;
        std::cout << "Invalid input! Re-enter: ";
    }
    return userChoice;
}

double getAmount()
{
    double amount;
    while (true) 
    {
        std::cin >> amount;
        if (!validateInput())
        {
            std::cout << "Invalid Input! Re-enter: \n";
        }
        else if(amount < 0)
        {
            std::cout << "Amount must be 0 or more: \n";
        }
        else
        {
            break;
        }
    }
    return amount;
}

std::string userIdInput()
{
    std::string userId;
    while (true) 
    {
        std::cin >> userId;
        if (validateInput()) break;
        std::cout << "Invalid input! Re-enter: ";
    }
    return userId;
}

std::string userPasswordInput()
{
    std::string userPassword;
    while (true) 
    {
        std::cin >> userPassword;
        if (validateInput()) break;
        std::cout << "Invalid input! Re-enter: ";
    }
    return userPassword;
}
