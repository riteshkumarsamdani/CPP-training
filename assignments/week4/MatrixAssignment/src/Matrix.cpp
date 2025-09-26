#include <iostream>
#include "Matrix.h"

Matrix::Matrix(int rows, int columns)
{
    matrix = new double*[rows];
    for(int row = 0; row < rows; ++row)
    {
        matrix[row] = new double[columns];
        for(int column = 0; column < columns; ++column)
        {    
            matrix[row][column] = 0;
        }
    }
}

Matrix::Matrix()
{
    rows = 0;
    columns = 0;
    matrix = nullptr;
}

Matrix::~Matrix()
{
    if (matrix)
    {
        int row = 0;
        while(row < rows)
        {
            delete[] matrix[row];
            row++;
        }
        delete[] matrix;
    }
}

void Matrix::displayMatrix() const
{
    int row = 0;
    if(!matrix)
    {
        std::cout << "Matrix is empty!!\n";
    }
    else
    {
        std::cout << "Elements for Matrix" << ":\n";
        while(row < rows)
        {
            int column = 0;
            while(column < columns)
            {
                std::cout <<  matrix[row][column] << "  ";
                column++;
            }
            std::cout << "\n";
            row++;
        }
    }
}

const int& Matrix::getRows() const
{
    return rows;
}

const int& Matrix::getColumns() const
{
    return columns;
}

void Matrix::setDimensions(int rows,int columns)
{
    this->rows = rows;
    this->columns = columns;
}

double** Matrix::matrixInputElements()
{
    int row = 0;
    while (row < rows)
    {
        int column = 0;
        while(column < columns)
        {
            matrix[row][column] = inputElement(row, column);
            column++;
        } 
        row++;
    }
    return matrix;   
}

Matrix Matrix::operator*(Matrix& secondMatrix)
{
    Matrix outputMatrix(rows, secondMatrix.getColumns());
    outputMatrix.setDimensions(rows, secondMatrix.getColumns());
    int firstMatrixRow = 0;
    while(firstMatrixRow < rows)
    {
        int secondMatrixColumn = 0;
        while(secondMatrixColumn < secondMatrix.getColumns())
        {
            int firstMatrixColumn = 0;
            outputMatrix.matrix[firstMatrixRow][secondMatrixColumn] = 0;
            while(firstMatrixColumn < columns)
            {
                outputMatrix.matrix[firstMatrixRow][secondMatrixColumn] += matrix[firstMatrixRow][firstMatrixColumn] * secondMatrix.matrix[firstMatrixColumn][secondMatrixColumn];
                firstMatrixColumn++;
            }
            secondMatrixColumn++;
        }
        firstMatrixRow++;
    }
    return outputMatrix;
}

Matrix Matrix::operator+(Matrix& secondMatrix)
{
    Matrix outputMatrix(rows, columns);
    int row = 0;
    outputMatrix.setDimensions(rows, columns);
    while(row < rows)
    {
        int column = 0;
        while(column < columns)
        {
            outputMatrix.matrix[row][column] = matrix[row][column] + secondMatrix.matrix[row][column];
            column++;
        }
        row++;
    }
    return outputMatrix;
}
