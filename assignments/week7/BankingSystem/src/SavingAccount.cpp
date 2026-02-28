#include "SavingAccount.h"
#include "Transaction.h"
#include <iostream>

SavingAccount::SavingAccount(double balance, int accountNumber)
    : Account(balance, accountNumber) {}

std::string SavingAccount::getAccountType() const
{ 
    return "Saving"; 
}

bool SavingAccount::deposit(double amount)
{
    if (amount <= 0) return false;
    balance += amount;
    Transaction* transaction = new Transaction("deposit", balance - amount, amount);
    transaction->setCurrentBalance(balance);
    transactions.push_back(transaction);
    std::cout << "transaction successful\n";
    return true;
}

bool SavingAccount::withdraw(double amount)
{
    bool success = false;
    if (amount <= balance && amount > 0) 
    {
        balance -= amount;
        Transaction* transaction = new Transaction("withdraw", balance + amount, amount);
        transaction->setCurrentBalance(balance);
        transactions.push_back(transaction);
        success = true;
        std::cout << "transaction successful\n";
    }
    else
    {
        std::cout << "don't have sufficient balance!!\n";
        std::cout << "transaction failed\n";
    }
    return success;
}
