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
    if (matrix != nullptr) 
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

void Matrix::displayMatrix(const std::string& matrixName) const
{
    int row =0;
    std::cout << "Elements for " << matrixName << ":\n";
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

const int& Matrix::getRows() const
{
    return rows;
}

const int& Matrix::getColumns() const
{
    return columns;
}

void Matrix::setDimensions(int& rows,int& columns)
{
    this->rows = rows;
    this->columns = columns;
}

double** Matrix::matrixInputElements(Matrix& matrix, const std::string& matrixName)
{
    int row = 0;
    while (row < rows)
    {
        int column = 0;
        while(column < columns)
        {
            matrix.matrix[row][column] = inputElement(row, column, matrixName);
            column++;
        } 
        row++;
    }
    return matrix.matrix;   
}

Matrix Matrix::operator*(Matrix& secondMatrix)
{
    int rows = this -> rows;
    int columns = secondMatrix.columns;
    int firstcloumns = this -> columns;
    Matrix outputMatrix(rows, columns);
    outputMatrix.setDimensions(rows, columns);
    int firstRow = 0;
    while(firstRow < rows)
    {
        int secondColumn = 0;
        while(secondColumn < columns)
        {
            int firstColumn = 0;
            outputMatrix.matrix[firstRow][secondColumn] = 0;
            while(firstColumn < firstcloumns)
            {
                outputMatrix.matrix[firstRow][secondColumn] += matrix[firstRow][firstColumn] * secondMatrix.matrix[firstColumn][secondColumn];
                firstColumn++;
            }
            secondColumn++;
        }
        firstRow++;
    }
    return outputMatrix;
}

Matrix Matrix::operator+(Matrix& secondMatrix)
{
    int rows = this -> rows;
    int columns = this -> columns;
    Matrix outputMatrix(rows, columns);
    int row = 0;
    outputMatrix.setDimensions(rows, columns);
    while(row < rows)
    {
        int column = 0;
        while(column < columns)
        {
            outputMatrix.matrix[row][column] = matrix[row][column] + secondMatrix.matrix[row][column];
        }
    }
    return outputMatrix;
}
