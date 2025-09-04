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

class CurrentAccount : public BankAccount {
public:
    CurrentAccount() {
        std::cout << "CurrentAccount created\n";
    }
};

int main() {
    SavingAccount sa;
    CurrentAccount ca;
    return 0;
}
