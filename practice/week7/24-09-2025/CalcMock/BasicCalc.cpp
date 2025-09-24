#include "BasicCalc.h"
#include <stdexcept>

int BasicCalc::add(int a, int b) 
{
    return a + b;
}

int BasicCalc::sub(int a, int b) 
{
    return a - b;
}

int BasicCalc::multiply(int a, int b) 
{
    return a * b;
}

int BasicCalc::division(int a, int b) 
{
    if (b == 0) throw std::runtime_error("Division by zero");
    return a / b;
}
