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
        char choice = utility.getChoice();
        utility.setChoice(choice);

        switch (choice)
        {
        case '+':
        {
            Matrix result = matrixOperation.matrixAddition(utility);
            result.displayMatrix("outputMatrix");
            break;
        }
        case '*':
        {
            Matrix result = matrixOperation.matrixMultiplication(utility);
            result.displayMatrix("outputMatrix");
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
