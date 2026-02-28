#include "Transaction.h"
#include "Account.h"
#ifndef LOAN_ACCOUNT_H
#define LOAN_ACCOUNT_H

class LoanAccount : public Account 
{
    public:
        LoanAccount(double balance, int accountNumber);
        bool deposit(double amount) override;
        bool withdraw(double amount) override;
        std::string getAccountType() const override;
};

#endif
