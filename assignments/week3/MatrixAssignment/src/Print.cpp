#include <iostream>
#include "Print.h"

void print(double** matrix, int rows, int colums)
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
