#include<iostream>
#include<limits>
#include<dlfcn.h>
#include"CalculatorExplicit.h"
#define LIBRARY_PATH "lib/libexplicitMath.so"

void* getHandle() {
    static void* handle = nullptr;
    if (handle == nullptr) {
        handle = dlopen(LIBRARY_PATH, RTLD_LAZY);
        if (!handle) {
            std::cerr << "Error: " << dlerror() << std::endl;
        }
    }
    return handle;
}

void closeHandle() {
    void* handle = getHandle();
    if (handle) {
        dlclose(handle);
    }
}

double validOperation(std::string oprator, double firstNumber, double secondNumber)
{
    double output;
    void* handle = getHandle();
    typedef double (*operationType)(double, double);
    operationType operation = (operationType)dlsym(handle, oprator.c_str());
    if (!operation) {
        std::cerr << "Symbol error: " << dlerror() << std::endl;
        output = std::numeric_limits<double>::max();
    }
    else
    {
        output = operation(firstNumber,secondNumber);
    }
    return output;
}

double inputNumber(std::string functionName)
{
    double number;
    typedef double(*inputNum)();
    void* handle = getHandle();
    inputNum getValidInput = (inputNum)dlsym(handle, functionName.c_str()); 
    if (!getValidInput) {
        std::cerr << "Symbol error: " << dlerror() << std::endl;
        number = std::numeric_limits<double>::max();
    }
    else
    {
        number = getValidInput();
    }
    return number;
}

char inputOperator(std::string funcName)
{
    char choice;
    typedef char(*inputOp)();
    void* handle = getHandle();
    inputOp validOperation = (inputOp)dlsym(handle, funcName.c_str()); 
    if (!validOperation) {
        std::cerr << "Symbol error: " << dlerror() << std::endl;
        choice = '1';
    }
    else
    {
        choice = validOperation();
    }
    return choice;
}

double calculate(char operationType, double firstNumber, double secondNumber) 
{
    double output;
    std::string operation;
    switch(operationType) {
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
            operation ="division";
            break;
        default: 
            std::cout << "Invalid operation\n";
            break;
    }
    output = validOperation(operation, firstNumber, secondNumber);
    return output;
}

void calculatorExplicit()
{
    char choice;
    double firstNumber, secondNumber;
    double output;
    std::string run;
    do 
    {
        std::cout << "Enter operation (+, -, *, /): ";
        choice = inputOperator("getValidOprator");
        std::cout << "Enter number 1: ";
        firstNumber = inputNumber("getValidInput");
        std::cout << "Enter number 2: ";
        secondNumber = inputNumber("getValidInput");
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
    closeHandle();
}
