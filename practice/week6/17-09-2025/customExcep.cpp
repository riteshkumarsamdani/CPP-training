#include <iostream>
#include <stdexcept>
#include <string>

class InsufficientFundsException : public std::runtime_error 
{
    public:
        InsufficientFundsException(const std::string& message) 
            : std::runtime_error(message) {}
};

class BankAccount {
    private:
        double balance;

    public:
        BankAccount(double initialBalance) : balance(initialBalance) {}

        void withdraw(double amount) 
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
};

int main()
{
    double amount;
    std::cout << "enter amount for balance\n";
    std::cin >> amount;
    BankAccount obj(amount);
    try
    {
        std::cout << "enter amount to withdraw\n";
        std::cin >> amount;
        obj.withdraw(amount);
    }
    catch(std::runtime_error& e)
    {
        std::cerr << "exception occured: " << e.what();
    }
    return 0;
}