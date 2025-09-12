#include <iostream>
#include <limits>
#include "InputHandler.h"
#include "InputValidations.h"

char getChoice()
{
    std::string userInput;
    char userChoice = '1';
    getline(std::cin >> std::ws, userInput);
    if(userInput == "+" || userInput == "*")
    {
        userChoice = *userInput.c_str();
    }
    else
    {
        std::cout << "Entered wrong choice\n";
    }
    return userChoice;
}

double getElement()
{
    std::cout << "Enter element\n";
    std::string userInput;
    getline(std::cin >> std::ws, userInput);
    double element = validateElement(userInput);
    while(element == doubleMax())
    {
        std::cout<< "Invalid input for elememt\n";
        getline(std::cin >> std::ws, userInput);
        element = validateElement(userInput);
    }
    return element;
}

int getDimension()
{
    std::string userInput;
    getline(std::cin >> std::ws, userInput);
    int dimension = validateDimension(userInput);
    while(dimension == intMax() || dimension < 0)
    {
        std::cout<< "Invalid input for dimension\n";
        getline(std::cin >> std::ws, userInput);
        dimension = validateDimension(userInput);
    }
    return dimension;
}
