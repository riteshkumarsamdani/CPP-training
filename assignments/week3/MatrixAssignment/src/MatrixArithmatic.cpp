#include <iostream>
#include "ArrayUtils.h"
#include "InputHandler.h"
#include "MatrixOperation.h"

double** matrixAddition(double** firstMatrix, double** secondMatrix, const Dimensions& dimensions)
{
    double** output = createArray(dimensions.firstColumns, dimensions.secondColumns,false);
    int row = 0;
    int column = 0;
    while(row < dimensions.firstRows)
    {
        column = 0;
        while(column < dimensions.firstColumns)
        {
            output[row][column] =firstMatrix[row][column] + secondMatrix[row][column];
            column++;
        }
        row++;
    }
    return output;
}

double** matrixMultiplication(double** firstMatrix, double** secondMatrix, const Dimensions& dimensions)
{
    double** output = createArray(dimensions.firstRows, dimensions.secondColumns,false);
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
