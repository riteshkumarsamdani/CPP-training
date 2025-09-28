// IAccount.h
#ifndef IACCOUNT_H
#define IACCOUNT_H
#include <vector>
#include "Transaction.h"

class IAccount 
{
public:
    virtual ~IAccount() = default;
    virtual int getAccountNumber() const = 0;
    virtual double getBalance() const = 0;
    virtual void transactionHandler() = 0;
    virtual void setBalance(double balance) = 0;
    virtual bool deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    virtual std::string getAccountSummary() const = 0;
    virtual std::vector<std::string> getTransactionHistory() const = 0;
    virtual std::vector<std::string> getMiniStatement() const = 0;
    virtual std::string getAccountType() const = 0;
};

#endif
