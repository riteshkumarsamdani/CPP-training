#include<iostream>
#include"Addition.h"

double addition(double number1, double number2)
{
    std::cout << "applying functionality for addition of two number\n";
    double ans = number1 + number2;
    std::cout << "addition of number " << number1 << " and " << number2 << " is " << ans << "\n";
    return ans;
}
