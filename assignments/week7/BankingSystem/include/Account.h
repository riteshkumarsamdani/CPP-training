#include "Transaction.h"
#include "IAccount.h"
#include <vector>
#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account : public IAccount 
{
    protected:
        int accountNumber;
        double balance;
        std::vector<Transaction*> transactions;

    public:
        Account(double balance, int accountNumber);
        virtual ~Account() = default;
        int getAccountNumber() const override;
        double getBalance() const override;
        void transactionHandler() override;
        void setBalance(double balance) override;
        std::vector<std::string> getTransactionHistory() const override;
        std::vector<std::string> getMiniStatement() const override;
        virtual bool deposit(double amount) = 0;
        virtual bool withdraw(double amount) = 0;
        std::string getAccountSummary() const override;
        virtual std::string getAccountType() const = 0;
};
#endif
