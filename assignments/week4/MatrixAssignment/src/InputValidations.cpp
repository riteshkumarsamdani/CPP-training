#include <iostream>
#include <sstream>
#include <limits>
#include "InputValidations.h"

double InputValidation::doubleMax()
{
    return std::numeric_limits<double>::max();
}

int InputValidation::intMax()
{
    return std::numeric_limits<int>::max();
}

double InputValidation::validateElement(const std::string& input)
{
    double value;
    std::stringstream output(input);
    if (!(output >> value && output.eof())) 
    {
        value = doubleMax();
    }
    return value;
}

int InputValidation::validateDimension(const std::string& input)
{
    int value;
    std::stringstream output(input);
    if (!(output >> value && output.eof())) 
    {
        value = intMax();
    } 
    return value;
}
