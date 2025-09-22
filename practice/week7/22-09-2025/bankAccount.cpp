#include "bankAccount.h"
#include <iostream>

BankAccount::BankAccount(double initialBalance) : balance(initialBalance) {}

void BankAccount::withdraw(double amount) 
{
    if (amount < 0) 
    {
        throw std::invalid_argument("Cannot withdraw a negative amount.");
    }
    if (amount > balance) 
    {
        throw InsufficientFundsException("Account balance is insufficient for this withdrawal.");
    }
    balance -= amount;
    std::cout << "Withdrawal successful. New balance is $" << balance << std::endl;
}
