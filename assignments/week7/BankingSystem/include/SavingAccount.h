#include "Transaction.h"
#include "Account.h"
#ifndef SAVING_ACCOUNT_H
#define SAVING_ACCOUNT_H

class SavingAccount : public Account 
{
    public:
        SavingAccount(double balance, int accountNumber);
        bool deposit(double amount) override;
        bool withdraw(double amount) override;
        std::string getAccountType() const override;
};

#endif
