#include <iostream>
#include "InputHandler.h"
#include "MatrixOperation.h"
#include "ArrayUtils.h"

Arrays inputDimensions(Dimensions& dimensions)
{
    Arrays arrays;
    std::cout << "Enter number of rows for first matrix\n";
    dimensions.firstRows = getDimension();
    std::cout << "Enter number of columns for first matrix\n";
    dimensions.firstColumns = getDimension();
    std::cout << "Enter number of rows for second matrix\n";
    dimensions.secondRows = getDimension();
    std::cout << "Enter number of columns for second matrix\n";
    dimensions.secondColumns = getDimension();
    return arrays;
}

int validInputAdditionRow(int firstMatrixRow, int secondMatrixRow)
{
    while(secondMatrixRow != firstMatrixRow)
    {
        std::cout << "Number of rows for second matrix should be equal to first!!\n";
        std::cout << "number of rows for first is: " << firstMatrixRow<< "\n";
        std::cout << "Enter number of rows for second matrix\n";
        secondMatrixRow = getDimension();
    }
    return secondMatrixRow;
}

int validInputMultiplicationRow(int firstMatrixColumn, int secondMatrixRow)
{
    while(secondMatrixRow != firstMatrixColumn)
    {
        std::cout << "Number of rows for second matrix should be equal to first matrix column!!\n";
        std::cout << "number of columns for first is: " << firstMatrixColumn << "\n";
        std::cout << "Enter number of rows for second matrix\n";
        secondMatrixRow = getDimension();
    }
    return secondMatrixRow;
}

int validInputAdditionColumn(int firstMatrixColumn, int secondMatrixColumn)
{
    while(firstMatrixColumn != secondMatrixColumn)
    {
        std::cout << "Number of columns for second matrix should be equal to first!!\n";
        std::cout << "number of columns for first is: " << firstMatrixColumn << "\n";
        std::cout << "Enter number of columns for second matrix\n";
        secondMatrixColumn = getDimension();
    }
    return secondMatrixColumn;
}

Arrays userInputArray(const char& choice, Dimensions& dimensions)
{
    Arrays arrays = inputDimensions(dimensions);   
    if(choice == '+')
    {
        if(dimensions.secondRows != dimensions.firstRows)
        {
            dimensions.secondRows = validInputAdditionRow(dimensions.firstRows, dimensions.secondRows);
        }
        if(dimensions.secondColumns != dimensions.firstColumns)
        {
            dimensions.secondColumns = validInputAdditionColumn(dimensions.firstColumns, dimensions.secondColumns);
        }
    }
    if(choice == '*')
    {
        if(dimensions.secondRows != dimensions.firstColumns)
        {
            dimensions.secondRows = validInputMultiplicationRow(dimensions.firstColumns, dimensions.secondRows);
        }
    }
    arrays.firstMatrix = createArray(dimensions.firstRows, dimensions.firstColumns, true);
    arrays.secondMatrix = createArray(dimensions.secondRows, dimensions.secondColumns, true);
    return arrays;
}

void printAllMatrix(const Arrays& arrays,const Dimensions& dimensions)
{
    std::cout << "printing values for firstMatrix\n";
    printArray(arrays.firstMatrix, dimensions.firstRows, dimensions.firstColumns);
    std::cout << "printing values for secondMatrix\n";
    printArray(arrays.secondMatrix, dimensions.secondRows, dimensions.secondColumns);
    std::cout << "printing values for addition\n";
    printArray(arrays.outputMatrix, dimensions.firstRows, dimensions.secondColumns);
}

void deleteAllMatrix(Arrays& arrays, const Dimensions& dimensions)
{
    deleteArray(arrays.firstMatrix, dimensions.firstRows);
    deleteArray(arrays.secondMatrix, dimensions.secondRows);
    deleteArray(arrays.outputMatrix, dimensions.firstRows);
}

void matrixOperations()
{
    Arrays arrays;
    Dimensions dimensions;
    std::string run = "1";
    do
    {
        std::cout << "enter choice '+' to addition of matrix and '*' to multiplication of matrix\n";
        char choice = getChoice();
        switch(choice)
        {
            case '+' :
                arrays = userInputArray(choice,dimensions);
                arrays.outputMatrix = matrixAddition(arrays.firstMatrix, arrays.secondMatrix, dimensions);
                break;
            case '*' :
                arrays = userInputArray(choice, dimensions);
                arrays.outputMatrix = matrixMultiplication(arrays.firstMatrix, arrays.secondMatrix, dimensions);
                break;
            default:
                std::cout << "enterd choice is invalid\n";
                break;
        }
        printAllMatrix(arrays,dimensions);
        deleteAllMatrix(arrays,dimensions);
        std::cout << "Enter 1 to re-run or press any key to terminate\n";
        std::cin >> run;
    }
    while(run == "1");
}
