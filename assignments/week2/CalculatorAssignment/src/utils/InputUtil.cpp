#include<iostream>
#include<limits>
#include<sstream>
#include"utils/InputUtils.h"

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
    return oprator.front();
}

double getValidInput() {
    std::string input;
    double value;
    while (true) 
    {
        std::getline(std::cin >> std::ws, input);
        std::stringstream output(input);
        if (output >> value && output.eof()) 
        {
            break;
        } 
        else 
        {
            std::cout << "Invalid input. Please enter a valid number.\n";
        }
    }
    return value;
}
