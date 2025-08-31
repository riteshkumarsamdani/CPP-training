#include <iostream>
#include "Input.h"
#include "MatrixOperation.h"

void matrixCaller()
{
    std::string run = "1";
    do
    {
        std::cout << "enter choice '+' to addition of matrix and '*' to multiplication of matrix\n";
        char choice = getChoice();
        switch(choice)
        {
            case '+' :
                matrixAddition();
                break;
            case '*' :
                matrixMultiplication();
                break;
            default:
                std::cout << "enterd choice is invalid\n";
                break;
        }
        std::cout << "Enter 1 to re-run or press any key to terminate\n";
        std::cin >> run;
    }
    while(run == "1");
}
