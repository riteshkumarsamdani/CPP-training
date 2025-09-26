#include <iostream>
#include "MatrixUtility.h"

double MatrixUtility::inputElement(int row, int column)
{
    std::cout << "Enter element at " << "(" << row << ", " << column << "):\n";
    std::string userInput;
    getline(std::cin >> std::ws, userInput);
    double element = validateElement(userInput);
    while(element == doubleMax())
    {
        std::cout << "Invalid input for elememt!!\n";
        std::cout << "Enter element at " << "(" << row << ", " << column << "):\n";
        getline(std::cin >> std::ws, userInput);
        element = validateElement(userInput);
    }
    return element;
}

int MatrixUtility::getDimension()
{
    std::string userInput;
    getline(std::cin >> std::ws, userInput);
    int dimension = validateDimension(userInput);
    while(dimension == intMax() || dimension < 0)
    {
        std::cout << "Invalid input for dimension!!\n";
        std::cout << "Enter dimension\n";
        getline(std::cin >> std::ws, userInput);
        dimension = validateDimension(userInput);
    }
    return dimension;
}

void MatrixUtility::setUserChoice(const char userChoice)
{
    this -> userChoice = userChoice;
}

char MatrixUtility::getUserChoice()
{
    std::string userInput;
    char inputChoice{};
    getline(std::cin >> std::ws, userInput);
    if(userInput == "+" || userInput == "*" || userInput == "1")
    {
        inputChoice = *userInput.c_str();
    }
    return inputChoice;
}
