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

class PremiumSaving : public SavingAccount {
public:
    PremiumSaving() {
        std::cout << "PremiumSaving created\n";
    }
};

int main() {
    PremiumSaving ps;
    return 0;
}
