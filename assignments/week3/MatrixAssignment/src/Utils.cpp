#include <iostream>
#include <limits>
#include <sstream>
#include "Utils.h"

int validInt(std::string input)
{
    int value;
    std::stringstream output(input);
    if (!(output >> value && output.eof())) 
    {
        value = std::numeric_limits<int>::max();
    } 
    return value;
}

double validDouble(std::string input)
{
    double value;
    std::stringstream output(input);
    if (!(output >> value && output.eof())) 
    {
        value = std::numeric_limits<double>::max();
    } 
    return value;
}
