#include <iostream>

class BankAccount {
private:
    double balance;

public:
    BankAccount(double b) : balance(b) {}
    friend void showBalance(const BankAccount& acc);
};

void showBalance(const BankAccount& acc) {
    std::cout << "Balance is: ₹" << acc.balance << std::endl;
}

int main() {
    BankAccount account(5000);
    showBalance(account); 
    return 0;
}
