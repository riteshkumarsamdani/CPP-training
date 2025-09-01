#include<iostream>
#include <limits>
#include"Input.h"
#include"Utils.h"

double doubleMax()
{
    return std::numeric_limits<double>::max();
}

int intMax()
{
    return std::numeric_limits<int>::max();
}

char getChoice()
{
    std::string input;
    char choice = '1';
    getline(std::cin >> std::ws, input);
    if(input == "+" || input == "*")
    {
        choice = *input.c_str();
    }
    else
    {
        std::cout << "Entered wrong choice\n";
    }
    return choice;
}

double getElement()
{
    std::cout << "Enter element\n";
    std::string input;
    getline(std::cin >> std::ws, input);
    double element = validDouble(input);
    while(element == doubleMax())
    {
        std::cout<< "Invalid input for elememt\n";
        getline(std::cin >> std::ws, input);
        element = validDouble(input);
    }
    return element;
}

int getDimension()
{
    std::string input;
    getline(std::cin >> std::ws, input);
    int dimension = validInt(input);
    while(dimension == intMax() || dimension < 0)
    {
        std::cout<< "Invalid input for dimension\n";
        getline(std::cin >> std::ws, input);
        dimension = validInt(input);
    }
    return dimension;
}
