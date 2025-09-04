#include <iostream>

class Loan {
public:
    Loan() {
        std::cout << "Loan created\n";
    }
};

class Insurance {
public:
    Insurance() {
        std::cout << "Insurance created\n";
    }
};

class FinancialProduct : public Loan, public Insurance {
public:
    FinancialProduct() {
        std::cout << "FinancialProduct created\n";
    }
};

int main() {
    FinancialProduct fp;
    return 0;
}
