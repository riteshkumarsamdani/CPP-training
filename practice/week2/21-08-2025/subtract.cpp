#include<iostream>
#include"subtract.h"

double subtract(double a, double b)
{
    std::cout << "applying functionality for subtarction of two number\n";
    double ans = a - b;
    std::cout << "addition of number " << a << " and " << b << " is " << ans;
    return ans;
}