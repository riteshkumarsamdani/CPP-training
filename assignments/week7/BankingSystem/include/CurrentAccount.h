#include "Transaction.h"
#include "Account.h"
#ifndef CURRENT_ACCOUNT_H
#define CURRENT_ACCOUNT_H

class CurrentAccount : public Account 
{
    private:
        double overdraftLimit;
    public:
        CurrentAccount(double balance, int accountNumber, double overdraftLimit = 5000);
        virtual bool deposit(double amount) override;
        virtual bool withdraw(double amount) override;
        std::string getAccountType() const override;
};

#endif
