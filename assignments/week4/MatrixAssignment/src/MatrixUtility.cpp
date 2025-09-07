#include <iostream>
#include "MatrixUtility.h"

double MatrixUtility::inputElement(int row, int column, const std::string& matrixName)
{
    std::cout << "Enter element at " << matrixName << "(" << row << ", " << column << "):\n";
    std::string input;
    getline(std::cin >> std::ws, input);
    double element = validElement(input);
    while(element == doubleMax())
    {
        std::cout << "Invalid input for elememt!!\n";
        std::cout << "Enter element at " << matrixName << "(" << row << ", " << column << "):\n";
        getline(std::cin >> std::ws, input);
        element = validElement(input);
    }
    return element;
}

int MatrixUtility::getDimension()
{
    std::string input;
    getline(std::cin >> std::ws, input);
    int dimension = validDimension(input);
    while(dimension == intMax() || dimension < 0)
    {
        std::cout << "Invalid input for dimension!!\n";
        std::cout << "Enter dimension\n";
        getline(std::cin >> std::ws, input);
        dimension = validDimension(input);
    }
    return dimension;
}

void MatrixUtility::setChoice(const char& choice)
{
    this -> choice = choice;
}

char MatrixUtility::getChoice()
{
    std::string input;
    char inputChoice{};
    getline(std::cin >> std::ws, input);
    if(input == "+" || input == "*" || input == "1")
    {
        inputChoice = *input.c_str();
    }
    return inputChoice;
}

