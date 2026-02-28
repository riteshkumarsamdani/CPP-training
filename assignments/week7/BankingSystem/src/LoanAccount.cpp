#include "LoanAccount.h"
#include "Transaction.h"
#include <iostream>

LoanAccount::LoanAccount(double balance, int accountNumber)
    : Account(balance, accountNumber) {}

bool LoanAccount::deposit(double amount)
{
    if (amount <= 0) return false;
    balance += amount;
    Transaction* transaction = new Transaction("deposit", balance - amount, amount);
    transaction->setCurrentBalance(balance);
    transactions.push_back(transaction);
    std::cout << "transaction successful\n";
    return true;
}

std::string LoanAccount::getAccountType() const 
{ 
    return "Loan"; 
}

bool LoanAccount::withdraw(double amount)
{
    std::cout << "can't withdraw money from loan account\n";
    std::cout << "transaction failed\n";
    return false;
}
