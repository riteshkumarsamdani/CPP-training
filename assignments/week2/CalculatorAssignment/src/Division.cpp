#include<iostream>
#include<limits>
#include"Division.h"

double division(double firstNumber, double secondNumber)
{
    double output;
    if(secondNumber == 0)
    {
        std::cout << "input is invalid! denominator can not be zero\n";
        output = std::numeric_limits<double>::max();
    }
    else
    {
        output=firstNumber/secondNumber;
    }
    return output;
}
