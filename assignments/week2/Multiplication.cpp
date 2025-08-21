#include<iostream>
#include"Multiplication.h"

double multiplication(double number1, double number2)
{
    std::cout << "applying functionality for multiplication of two number\n";
    double ans = number1 * number2;
    std::cout << "multiplication of number " << number1 << " and " << number2 << " is " << ans << "\n";
    return ans;
}
