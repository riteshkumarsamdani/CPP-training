#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <iostream>
#include <limits>
#include <string>

class InputHandler
{
    public:
        template <typename T>
        void getUserInput(const std::string& prompt, T& userInput);

    private:
        void ignoreLine();
        bool validateInput();
};

template <typename T>
void InputHandler::getUserInput(const std::string& prompt, T& userInput)
{
    std::cout << prompt;
    while (true) 
    {
        std::cin >> userInput;
        if (validateInput()) 
        {
            break;
        }
        std::cout << "Input failed!! " << prompt << "\n";
    }
}

#endif
