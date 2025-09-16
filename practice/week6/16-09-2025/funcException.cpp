#include <iostream>
#include <stdexcept>

double divide(double a, double b) 
{
    if (b == 0) 
    {
        throw std::runtime_error("Error: Division by zero attempted.");
    }
    return a / b;
}

void doCalculation(double x, double y) {
    std::cout << "Performing calculation..." << std::endl;
    double result = divide(x, y);
    std::cout << "Result of division is: " << result << std::endl;
}

int main() {
    double num1 = 10.0;
    double num2 = 0.0;
    try 
    {
        doCalculation(num1, num2);
    }
    catch (const std::runtime_error& e) 
    {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
    std::cout << "Program continues execution." << std::endl;
    return 0;
}
