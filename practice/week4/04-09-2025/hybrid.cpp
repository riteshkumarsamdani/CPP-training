#include <iostream>

class BankAccount {
public:
    BankAccount() {
        std::cout << "BankAccount created\n";
    }
};

class SavingAccount : public BankAccount {
public:
    SavingAccount() {
        std::cout << "SavingAccount created\n";
    }
};

class Loan {
public:
    Loan() {
        std::cout << "Loan created\n";
    }
};

class PremiumCustomer : public SavingAccount, public Loan {
public:
    PremiumCustomer() {
        std::cout << "PremiumCustomer created\n";
    }
};

int main() {
    PremiumCustomer pc;
    return 0;
}
