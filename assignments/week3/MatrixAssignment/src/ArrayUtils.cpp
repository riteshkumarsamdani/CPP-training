#include <iostream>
#include "ArrayUtils.h"
#include "InputHandler.h"

double** createArray(int rows, int columns, bool isUserInput)
{
    double **output = new double*[rows];
    for(int row = 0; row < rows; ++row)
    {
        output[row] = new double[columns];
        for(int column = 0; column < columns; ++column)
        {
            if(isUserInput)
            {
                output[row][column] = getElement();
            }
            else
            {
                output[row][column] = 0;
            }
        }
    }
    return output;
}

void deleteArray(double** array, int rows)
{
    int row = 0;
    while(row < rows)
    {
        delete[] array[row];
        row++;
    }
    delete[] array;
}

void printArray(double** matrix, int rows, int colums)
{
    int row = 0;
    int column = 0;
    while(row < rows)
    {
        column = 0;
        while(column < colums)
        {
            std::cout << *(*(matrix+row) + column) << "  ";
            column++;
        }
        std::cout << "\n";
        row++;
    }
}
