#include <iostream>
#include "Account.h"
#include "InputHandler.h"

Account::Account(double balance, int accountNumber)
{
    this -> balance = balance;
    this -> accountNumber = accountNumber;
}

std::string Account::getAccountSummary() const 
{
    return "Account No: " + std::to_string(accountNumber) +
           ", Type: " + getAccountType() +
           ", Balance: ₹" + std::to_string(balance);
}


int Account::getAccountNumber() const
{
    return accountNumber;
}

double Account::getBalance() const
{
    return balance;
}

void Account::setBalance(double balance)
{
    this -> balance = balance;
}

std::vector<std::string> Account::getTransactionHistory() const
{
    std::vector<std::string> transactionHistory;
    for (const auto& transaction : transactions) {
        transactionHistory.push_back(transaction->getTransaction());
    }
    return transactionHistory;
}

std::vector<std::string> Account::getMiniStatement() const
{
    int totalTransaction = transactions.size();
    int count = (totalTransaction < 5) ? totalTransaction : 5;
    int iterator = totalTransaction - count;
    std::vector<std::string> miniStatement;
    while(iterator < totalTransaction)
    {
        miniStatement.push_back(transactions[iterator]->getTransaction());
        iterator++;
    }
    return miniStatement;
}

void Account::transactionHandler()
{
    bool run = true;
    int userChoice;
    double amount;
    while(run)
    {
        amount = 0;
        std::cout << "1. for deposite\n";
        std::cout << "2. for withdraw\n";
        std::cout << "3. for exit\n";
        getUserInput("Enter your choice: ", userChoice);
        switch (userChoice)
        {
            case 1:
            {
                getPositiveUserInput("enter amount for deposite\n",amount);
                deposit(amount);
                break;
            }
            case 2:
            {
                getPositiveUserInput("enter amount for withdraw\n",amount);
                withdraw(amount);
                break;
            }
            case 3:
            {
                run = false;
                break;
            }
            default:
            {
                std::cout << "Invalid choice!!\n";
                break;
            }
        }
    }
}
