#include <iostream>
#include <limits>
#include "InputHandler.h"

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool validateInput()
{
    bool isValidInput = true;
    if (std::cin.eof())
    {
        exit(1);
    }
    if (std::cin.fail() || std::cin.peek() != '\n') 
    {
        std::cin.clear();
        isValidInput = false;
    }
    ignoreLine();
    return isValidInput;
}

bool getPositiveUserInput(const std::string& prompt, double& value) 
{
    do 
    {
        getUserInput(prompt, value);
        if (value < 0) 
        {
            std::cout << "Amount can't be negative. Please try again.\n";
        }
    } while (value < 0);
    return true;
}
