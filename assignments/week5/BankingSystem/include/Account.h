#include "Transaction.h"
#include <vector>
#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
private:
    double balance;
    int accountNumber;
    std::vector<Transaction*> transactions;
public:
    Account(int balance, int accountno);
    int getAccountNumber();
    double getBalance();
    void transact();
    void setBalance(int balance);
    void showAllTransaction();
    void withdraw();
    void deposit();
    void showMiniStatement();
};

#endif
