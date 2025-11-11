#include <iostream>
#include <limits>
#include "InputHandler.h"

void InputHandler::ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool InputHandler::validateInput()
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

void InputHandler::getLineInput(const std::string& prompt, std::string& userInput)
{
    std::cout << prompt;
    while (true)
    {
        std::getline(std::cin >> std::ws, userInput);
        if (!userInput.empty()) break;
        std::cout << "Input failed!! " << prompt << "\n";
    }
}
