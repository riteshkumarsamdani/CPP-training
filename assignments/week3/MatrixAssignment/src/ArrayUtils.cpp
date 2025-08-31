#include<iostream>
#include"ArrayUtils.h"
#include"Input.h"

double** createArray(int rows, int columns, bool flag)
{
    double **output = new double*[rows];
    for(int row = 0; row < rows; ++row)
    {
        output[row] = new double[columns];
        for(int column = 0; column < columns; ++column)
        {
            if(flag)
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

void deleteArray(double** array,int rows)
{
    int row = 0;
    while(row < rows)
    {
        delete[] array[row];
        row++;
    }
    delete[] array;
}
