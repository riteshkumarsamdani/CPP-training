#include<iostream>
#include"add.h"

double add(double a, double b)
{
    std::cout << "applying functionality for addition of two number\n";
    double ans = a + b;
    std::cout << "addition of number " << a << " and " << b << " is " << ans;
    return ans;
}