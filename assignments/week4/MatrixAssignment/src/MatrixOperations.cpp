#include "MatrixOperations.h"
#include <iostream>

Matrix MatrixOperations::createMatrix(MatrixUtility& utility) 
{
    int rows, columns;
    std::cout << "Enter number of rows and columns for matrix:\n";
    rows = utility.getDimension();
    columns = utility.getDimension();
    Matrix matrix(rows, columns);
    matrix.setDimensions(rows, columns);
    return matrix;
}

Matrix MatrixOperations::matrixAddition(MatrixUtility& utility) 
{
    Matrix firstMatrix = createMatrix(utility);
    Matrix secondMatrix = createMatrix(utility);
    bool isValidDimension = true;
    if (firstMatrix.getRows() == secondMatrix.getRows() && firstMatrix.getColumns() == secondMatrix.getColumns()) 
    {
        firstMatrix.matrixInputElements();
        secondMatrix.matrixInputElements();
    } 
    else 
    {
        isValidDimension = false;
        std::cout << "Invalid dimensions! Both matrices must have the same dimensions.\n";
    }
    return (isValidDimension == true) ? (firstMatrix + secondMatrix) : Matrix();
}

Matrix MatrixOperations::matrixMultiplication(MatrixUtility& utility) 
{
    Matrix firstMatrix = createMatrix(utility);
    Matrix secondMatrix = createMatrix(utility);
    bool isValidDimension = true;
    if (firstMatrix.getColumns() == secondMatrix.getRows()) 
    {
        firstMatrix.matrixInputElements();
        secondMatrix.matrixInputElements();
    } 
    else 
    {
        isValidDimension = false;
        std::cout << "Invalid dimensions! Columns of first must equal rows of second.\n";
    }
    return (isValidDimension == true) ? (firstMatrix * secondMatrix) : Matrix();
}
