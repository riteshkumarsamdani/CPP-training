#include <iostream>

class Account {
public:
    virtual void calculateInterest() = 0;
};

class FixedDeposit : public Account {
public:
    FixedDeposit() {
        std::cout << "FixedDeposit created\n";
    }
    void calculateInterest() override {
        std::cout << "Interest is 6.5% annually\n";
    }
};

int main() {
    FixedDeposit fd;
    fd.calculateInterest();
    return 0;
}
