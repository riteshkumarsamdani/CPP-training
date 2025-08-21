#include<iostream>
#include"Subtract.h"

double subtract(double number1, double number2)
{
    std::cout << "applying functionality for subtarction of two number\n";
    double ans = number1 - number2;
    std::cout << "subtraction of number " << number1 << " and " << number2 << " is " << ans << "\n";
    return ans;
}
