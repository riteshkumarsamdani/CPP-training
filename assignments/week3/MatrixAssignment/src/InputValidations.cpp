#include <iostream>
#include <limits>
#include <sstream>
#include "InputValidations.h"

double doubleMax()
{
    return std::numeric_limits<double>::max();
}

int intMax()
{
    return std::numeric_limits<int>::max();
}

int validateDimension(const std::string& input)
{
    int value;
    std::stringstream output(input);
    if (!(output >> value && output.eof())) 
    {
        value = intMax();
    } 
    return value;
}

double validateElement(const std::string& input)
{
    double value;
    std::stringstream output(input);
    if (!(output >> value && output.eof())) 
    {
        value = doubleMax();
    } 
    return value;
}
