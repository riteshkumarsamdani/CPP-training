#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <iostream>
#include <limits>
#include <string>

void ignoreLine();
bool validateInput();
bool getPositiveUserInput(const std::string& prompt, double& value);
template <typename T>
bool getUserInput(const std::string& prompt, T& userInput)
{
    std::cout << prompt;
    while (true) {
        std::cin >> userInput;
        if (validateInput()) {
            break;
        }
        std::cout << "Input failed!! " << prompt << "\n";
    }
    return true;
}

#endif
