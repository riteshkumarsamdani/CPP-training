#include "CurrentAccount.h"
#include "Transaction.h"
#include <iostream>

CurrentAccount::CurrentAccount(double balance, int accountNumber, double overdraftLimit)
    : Account(balance, accountNumber), overdraftLimit(overdraftLimit) {}

bool CurrentAccount::deposit(double amount)
{
    if (amount <= 0) return false;
    balance += amount;
    Transaction* transaction = new Transaction("deposit", balance - amount, amount);
    transaction->setCurrentBalance(balance);
    transactions.push_back(transaction);
    std::cout << "transaction successful\n";
    return true;
}

std::string CurrentAccount::getAccountType() const 
{ 
    return "Current"; 
}

bool CurrentAccount::withdraw(double amount)
{
    bool success = false;
    if (amount > 0 && amount <= balance + overdraftLimit) 
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
        std::cout << "limit exceeds!!\n";
        std::cout << "transaction failed\n";
    }
    return success;
}
