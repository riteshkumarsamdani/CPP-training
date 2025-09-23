#include <iostream>
#include <exception>
#include "Calc.h"

int main() 
{
    Calc calculator;
    int a, b, choice;
    std::cout << "Enter two integers: ";
    std::cin >> a >> b;
    std::cout << "\nChoose operation:\n";
    std::cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n";
    std::cout << "Enter choice (1-4): ";
    std::cin >> choice;
    try {
        switch (choice) 
        {
            case 1:
                std::cout << "Result: " << calculator.add(a, b) << "\n";
                break;
            case 2:
                std::cout << "Result: " << calculator.sub(a, b) << "\n";
                break;
            case 3:
                std::cout << "Result: " << calculator.multiply(a, b) << "\n";
                break;
            case 4:
                std::cout << "Result: " << calculator.division(a, b) << "\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << "\n";
    }
    return 0;
}
