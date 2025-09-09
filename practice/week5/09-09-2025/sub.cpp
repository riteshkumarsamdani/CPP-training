#include <iostream>
#include "temp.h"

int Calc::x = 0;

int Calc::sub(int a, int b)
{
    x++;
    return a-b;
}