#include <iostream>
#include "Account.h"
#include "InputValidator.h"

Account::Account(int balance, int accountNumber)
{
    this -> balance = balance;
    this -> accountNumber = accountNumber;
}

int Account::getAccountNumber()
{
    return accountNumber;
}

double Account::getBalance()
{
    return balance;
}

void Account::setBalance(int balance)
{
    this -> balance = balance;
}

void Account::showAllTransaction()
{
    int iterator = 0;
    while(iterator < transactions.size())
    {
        transactions[iterator] -> showTransactions();
        std::cout << "\n";
        iterator++;
    }
}

void Account::showMiniStatement()
{
    int totalTransaction = transactions.size();
    int count = (totalTransaction < 5) ? totalTransaction : 5;
    int iterator = totalTransaction - count;
    while(iterator < totalTransaction)
    {
        transactions[iterator] -> showTransactions();
        std::cout << "\n";
        iterator++;
    }
}

void Account::withdraw()
{
    std::string type;
    double amount;
    type = "withdraw";
    std::cout << "enter money\n";
    amount = getAmount();
    if(amount <= balance)
    {
        Transaction* transaction = new Transaction(type,balance,amount);
        balance = transaction -> getCurrentBal();
        transaction -> showTransactions();
        transactions.push_back(transaction);
    }
    else 
    {
        std::cout << "you can not withrow more than balance!! balance:" << balance << "\n";
    }
}

void Account::deposit()
{
    std::string transactionType;
    double amount;
    transactionType = "deposit";
    std::cout << "enter money\n";
    amount = getAmount();
    Transaction* transaction = new Transaction(transactionType, balance, amount);
    balance = transaction -> getCurrentBal();
    transaction -> showTransactions();
    transactions.push_back(transaction);
}

void Account::transact()
{
    bool run = true;
    char userChoice;
    while(run)
    {
        std::cout << "1 for deposite\n";
        std::cout << "2 for withdraw\n";
        std::cout << "3 for exit\n";
        userChoice = userInputChoice();
        switch (userChoice)
        {
            case 1:
            {
                deposit();
                break;
            }
            case 2:
            {
                withdraw();
                break;
            }
            case 3:
            {
                run = false;
                break;
            }
            default:
            {
                std::cout << "wrong choice!!\n";
                break;
            }
        }
    }
}
