#include <iostream>
#include "ArrayUtils.h"
#include "Print.h"
#include "Input.h"
#include "MatrixOperation.h"

double** addition(double** firstMatrix, double** secondMatrix, int rows, int columns)
{
    double** output = createArray(rows, columns, false);
    int row = 0;
    int column = 0;
    while(row < rows)
    {
        column = 0;
        while(column < columns)
        {
            output[row][column] = firstMatrix[row][column] + secondMatrix[row][column];
            column++;
        }
        row++;
    }
    return output;
}

void matrixAddition()
{
    int rows, columns;
    std::cout << "Enter number of rows\n";
    rows = getDimension();
    std::cout << "Enter number of columns\n";
    columns = getDimension();
    std::cout << "dimensions of second matrix is same as first\n";
    double** firstMatrix = createArray(rows, columns, true);
    double** secondMatrix = createArray(rows, columns, true);
    double** output = addition(firstMatrix, secondMatrix, rows, columns);
    std::cout << "printing values for firstMatrix\n";
    print(firstMatrix, rows, columns);
    std::cout << "printing values for secondMatrix\n";
    print(secondMatrix, rows, columns);
    std::cout << "printing values for addition\n";
    print(output, rows, columns);
    deleteArray(firstMatrix, rows);
    deleteArray(secondMatrix, rows);
    deleteArray(output, rows);
}
