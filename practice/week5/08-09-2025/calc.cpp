#include <iostream>

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Calculator calc;
    std::cout << "Sum of two integers: " << calc.add(5, 10) << std::endl;
    std::cout << "Sum of two doubles: " << calc.add(5.5, 10.5) << std::endl;
    std::cout << "Sum of three integers: " << calc.add(1, 2, 3) << std::endl;
    return 0;
}