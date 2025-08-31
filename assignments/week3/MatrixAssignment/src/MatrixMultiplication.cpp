#include <iostream>
#include "ArrayUtils.h"
#include "Print.h"
#include "Input.h"
#include "MatrixOperation.h"

struct Dimensions
{
    int firstRows;
    int secondRows;
    int firstColumns;
    int secondColumns;
};

double** multiplication(double** firstMatrix, double** secondMatrix, Dimensions dimensions)
{
    double** output = createArray(dimensions.firstRows, dimensions.secondColumns, false);
    int firstRow = 0;
    while(firstRow < dimensions.firstRows)
    {
        int secondColumn = 0;
        while(secondColumn < dimensions.secondColumns)
        {
            int firstColumn = 0;
            output[firstRow][secondColumn] = 0;
            while(firstColumn < dimensions.firstColumns)
            {
                output[firstRow][secondColumn] += firstMatrix[firstRow][firstColumn] * secondMatrix[firstColumn][secondColumn];
                firstColumn++;
            }
            secondColumn++;
        }
        firstRow++;
    }
    return output;
}

void matrixMultiplication()
{
    Dimensions dimensions;
    std::cout << "Enter number of rows for first matrix\n";
    dimensions.firstRows = getDimension();
    std::cout << "Enter number of columns for first matrix\n";
    dimensions.firstColumns = getDimension();
    std::cout << "Number of rows for second matrix is set as same as columns for first matrix\n";
    dimensions.secondRows = dimensions.firstColumns;
    std::cout << "Enter number of columnsfor second matrix\n";
    dimensions.secondColumns = getDimension();
    double** firstMatrix = createArray(dimensions.firstRows, dimensions.firstColumns, true);
    double** secondMatrix = createArray(dimensions.secondRows, dimensions.secondColumns, true);
    double** output = multiplication(firstMatrix, secondMatrix, dimensions);
    std::cout << "printing values for firstMatrix\n";
    print(firstMatrix, dimensions.firstRows, dimensions.firstColumns);
    std::cout << "printing values for secondMatrix\n";
    print(secondMatrix, dimensions.secondRows, dimensions.secondColumns);
    std::cout << "printing values for addition\n";
    print(output, dimensions.firstRows, dimensions.secondColumns);
    deleteArray(firstMatrix, dimensions.firstRows);
    deleteArray(secondMatrix, dimensions.secondRows);
    deleteArray(output, dimensions.firstRows);
}
