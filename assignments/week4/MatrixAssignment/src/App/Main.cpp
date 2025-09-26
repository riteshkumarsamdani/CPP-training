#include <iostream>
#include "Matrix.h"
#include "MatrixOperations.h"
#include "MatrixUtility.h"

void matrixOperationHandler()
{
    MatrixUtility utility;
    MatrixOperations matrixOperation;
    bool run = true;
    while (run)
    {
        std::cout << "Enter choice:\n+ for matrix addition\n* for multiplication\n1 for exit\n";
        char choice = utility.getUserChoice();
        utility.setUserChoice(choice);

        switch (choice)
        {
        case '+':
        {
            Matrix result = matrixOperation.matrixAddition(utility);
            result.displayMatrix();
            break;
        }
        case '*':
        {
            Matrix result = matrixOperation.matrixMultiplication(utility);
            result.displayMatrix();
            break;
        }
        case '1':
            run = false;
            break;
        default:
            std::cout << "Invalid choice\n";
            break;
        }
    }
}

int main()
{
    matrixOperationHandler();
    return 0;
}
