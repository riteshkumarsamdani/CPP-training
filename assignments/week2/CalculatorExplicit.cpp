#include<iostream>
#include<dlfcn.h>
#include<limits>
#include"Addition.h"
#include"Multiplication.h"
#include"Division.h"
#include"Subtract.h"
#include"InputUtil.h"

typedef double (*mathFunc)(double, double);

mathFunc validOperation(std::string oprator)
{
    void* handle = dlopen("./libmath.so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "Error: " << dlerror() << std::endl;
        return nullptr;
    }
    mathFunc operation = (mathFunc)dlsym(handle, oprator.c_str());
    if (!operation) {
        std::cerr << "Symbol error: " << dlerror() << std::endl;
        dlclose(handle);
        return nullptr;
    }
    return operation;
}

double inputNumber(std::string funcName)
{
    double number;
    typedef double(*inputNum)();
    void* handle = dlopen("./libmath.so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "Error: " << dlerror() << std::endl;
        number = std::numeric_limits<double>::max();
        return number;
    }
    inputNum getValidInput = (inputNum)dlsym(handle, funcName.c_str()); 
    if (!getValidInput) {
        std::cerr << "Symbol error: " << dlerror() << std::endl;
        dlclose(handle);
        return number;
    }
    number = getValidInput();
    return number;
}

double calculate(char op, double number1, double number2) 
{
    double ans;
    std::string operation;
    switch(op) {
        case '+': 
            operation = "addition";
            break;
        case '-': 
            operation ="subtract";
            break;
        case '*': 
            operation ="multiplication";
            break;
        case '/': 
            if(number2 == 0)
            {
                while(number2 == 0)
                {
                    std::cout << "denominator can not be zero\n";
                    std::cout << "enter valid input\n";
                    number2 = inputNumber("getValidInput");
                }
            }
            operation ="division";
            break;
        default: 
            std::cout << "Invalid operation\n";
            break;
    }
    mathFunc mathOperation = validOperation(operation);
    ans = mathOperation(number1, number2);
    return ans;
}

char inputOperator(std::string funcName)
{
    char choice;
    typedef char(*inputOp)();
    void* handle = dlopen("./libmath.so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "Error: " << dlerror() << std::endl;
        return '1';
    }
    inputOp validOperation = (inputOp)dlsym(handle, funcName.c_str()); 
    if (!validOperation) {
        std::cerr << "Symbol error: " << dlerror() << std::endl;
        dlclose(handle);
        return '1';
    }
    choice = validOperation();
    dlclose(handle);
    return choice;
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
        choice = inputOperator("getValidOprator");
        std::cout << "Enter number 1: ";
        number1 = inputNumber("getValidInput");
        std::cout << "Enter number 2: ";
        number2 = inputNumber("getValidInput");
        ans = calculate(choice, number1, number2);
        std::cout << "Result: " << ans << "\n";
        std::cout << "Enter 1 to continue or anything else to exit: ";
        std::cin >> run;
    } 
    while(run == "1");
    return 0;
}
