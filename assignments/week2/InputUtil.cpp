#include <iostream>
#include <limits>
#include "InputUtil.h"

char getValidOprator()
{
    std::string oprator;
    while(true)
    {
        getline(std::cin >> std::ws, oprator);
        if(oprator == "+" || oprator == "-" || oprator == "/" || oprator == "*")
        {
            break;
        }
        else
        {
            std::cout << "invalid input for oprator\n";
            std::cout << "please select (+, -, *, /)\n";
        }
    }
    return *oprator.c_str();
}

double getValidInput() 
{
    double value;
    while (true) {
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid number.\n";
        } else {
            break;
        }
    }
    return value;
}
