#include<iostream>
#include"Division.h"

double division(double number1, double number2)
{
    std::cout << "applying functionality for division of two number\n";
    double ans = number1 / number2;
    std::cout << "division of number " <<  number1 << " and " << number2 << " is " << ans << "\n";
    return ans;
}
