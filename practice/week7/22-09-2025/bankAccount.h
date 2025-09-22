#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#include <stdexcept>
#include <string>

class InsufficientFundsException : public std::runtime_error 
{
    public:
        InsufficientFundsException(const std::string& message)
            : std::runtime_error(message) {}
};

class BankAccount 
{
    private:
        double balance;
    public:
        BankAccount(double initialBalance);
        void withdraw(double amount);
};

#endif
