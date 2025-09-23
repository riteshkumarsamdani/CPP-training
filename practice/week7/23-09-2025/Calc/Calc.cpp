#include <iostream>
#include <exception>
#include "Calc.h"

int Calc::add(int a, int b)
{
    return a+b;
}

int Calc::sub(int a, int b)
{
    return a-b;
}
int Calc::multiply(int a, int b)
{
    return a*b;
}
int Calc::division(int a, int b)
{
    if(b==0)
    {
        throw std::runtime_error("divide by zero exception");
    }
    return a/b;
}
