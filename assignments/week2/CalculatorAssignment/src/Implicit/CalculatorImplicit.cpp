#include<iostream>
#include<limits>
#include"Addition.h"
#include"Multiplication.h"
#include"Division.h"
#include"Subtract.h"
#include"utils/InputUtils.h"
#include"CalculatorImplicit.h"

double calculate(char operation, double firstNumber, double secondNumber) 
{
    double output;
    switch(operation) {
        case '+': 
            output = addition(firstNumber, secondNumber);
            break;
        case '-': 
            output = subtract(firstNumber, secondNumber);
            break;
        case '*': 
            output = multiplication(firstNumber, secondNumber);
            break;
        case '/': 
            output = division(firstNumber, secondNumber);
            break;
        default: 
            std::cout << "Invalid operation\n";
            break;
    }
    return output;
}

void calculatorImplicit()
{
    char choice;
    double firstNumber, secondNumber;
    double output;
    std::string run;
    do 
    {
        std::cout << "Enter operation (+, -, *, /): ";
        choice = getValidOprator();
        std::cout << "Enter number 1: ";
        firstNumber = getValidInput();
        std::cout << "Enter number 2: ";
        secondNumber = getValidInput();
        output = calculate(choice, firstNumber, secondNumber);
        if(output == std::numeric_limits<double>::max())
        {
            break;
        }
        else
        {
            std::cout << "Result: " << output << "\n";
        }
        std::cout << "Enter 1 to continue or anything else to exit: ";
        std::cin >> run;
    } 
    while(run == "1");
}
