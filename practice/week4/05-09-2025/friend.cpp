#include <iostream>

class Wallet;

class BankAccount {
private:
    double balance;
public:
    BankAccount(double b) : balance(b) {}
    friend double totalAssets(const BankAccount&, const Wallet&);
};

class Wallet {
private:
    double cash;
public:
    Wallet(double c) : cash(c) {}
    friend double totalAssets(const BankAccount&, const Wallet&);
};

double totalAssets(const BankAccount& acc, const Wallet& w) {
    return acc.balance + w.cash;
}

int main() {
    BankAccount acc(8000);
    Wallet w(2000);
    std::cout << "Total Assets: ₹" << totalAssets(acc, w) << std::endl;
    return 0;
}
