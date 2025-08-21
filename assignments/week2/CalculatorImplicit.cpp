#include<iostream>
#include"Addition.h"
#include"Multiplication.h"
#include"Division.h"
#include"Subtract.h"
#include"InputUtil.h"

double calculate(char op, double number1, double number2) 
{
    double ans;
    switch(op) {
        case '+': 
            ans = addition(number1, number2);
            break;
        case '-': 
            ans = subtract(number1, number2);
            break;
        case '*': 
            ans = multiplication(number1, number2);
            break;
        case '/': 
            if(number2 == 0)
            {
                while(number2 == 0)
                {
                    std::cout << "denominator can not be zero\n";
                    std::cout << "enter valid input\n";
                    number2 = getValidInput();
                }
            }
            ans = division(number1, number2);
            break;
        default: 
            std::cout << "Invalid operation\n";
            break;
    }
    return ans;
}

int main() 
{
    char choice;
    double number1, number2;
    double ans;
    std::string run;
    do 
    {
        std::cout << "Enter operation (+, -, *, /): ";
        choice = getValidOprator();
        std::cout << "Enter number 1: ";
        number1 = getValidInput();
        std::cout << "Enter number 2: ";
        number2 = getValidInput();
        ans = calculate(choice, number1, number2);
        std::cout << "Result: " << ans << "\n";
        std::cout << "Enter 1 to continue or anything else to exit: ";
        std::cin >> run;
    } 
    while(run == "1");
    return 0;
}
