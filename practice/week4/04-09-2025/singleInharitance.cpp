#include <iostream>

class BankAccount
{
    int accountNumber{111};
    double amount{};
    public:
    void setAmount(double amount)
    {
        this->amount = amount;
    }
    double getAmount()
    {
        return amount;
    }
    BankAccount()
    {
        std::cout << "This is bankaccount\n";
    }
};

class Saving: public BankAccount
{
    double interestRate{5};
    public:
    double getInterestRate()
    {
        return interestRate;
    }
    Saving()
    {
        std::cout << "this is saving account\n";
    }
};

int main()
{
    Saving s1;
    BankAccount b1;
    s1.setAmount(1000);
    std::cout << "amount is :" << s1.getAmount() << "\n";
    std::cout << "interest is :" << s1.getInterestRate() << "\n";
    return 0;
}
