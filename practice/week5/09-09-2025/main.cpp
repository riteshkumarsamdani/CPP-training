#include <iostream>
#include "temp.h"
#define PI 3.2
// int z=2;
// z=3;
int z=4;
static int r=2;
int main()
{
    r = 5;
    static int x = 10;
    Calc c;
    c.sub(2,3);
    std::cout << Calc::x << std::endl << PI << std::endl << x << std::endl << PI << std::endl << r;
    return 0;
}