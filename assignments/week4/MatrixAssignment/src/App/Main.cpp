#include <iostream>
#include "Matrix.h"
#include "MatrixOperations.h"
#include "MatrixUtility.h"

// void matrixOperationHandler(Matrix& userMatrix)
// {
//     bool run = true;
//     do
//     {
//         std::cout << "Enter choice:\n" << "+ for matrix addition\n" << "* for multiplication\n" << "1 for exit\n";
//         char choice = userMatrix.getChoice();
//         userMatrix.setChoice(choice);
//         MatrixOperations matrixOperation;
//         switch (choice)
//         {
//         case '+':
//             userMatrix = matrixOperation.matrixAddition();
//             userMatrix.displayMatrix("outputMatrix");
//             break;
            
//             case '*':
//             userMatrix = matrixOperation.matrixMultiplication();
//             userMatrix.displayMatrix("outputMatrix");
//             break;

//         case '1':
//             run = false;
//             break;

//         default:
//             std::cout << "Invalid choice\n";
//             break;
//         }
//     } 
//     while (run);
// }

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
    // Matrix userMatrix;
    matrixOperationHandler();
    return 0;
}
