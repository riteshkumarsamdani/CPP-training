#include "MatrixOperations.h"
#include <iostream>

Matrix MatrixOperations::matrixAddition(MatrixUtility& utility) {
    std::cout << "Enter number of rows and colums for first matrix:\n";
    int firstRows = utility.getDimension();
    int firstColumns = utility.getDimension();
    std::cout << "Enter number of rows and columns for second matrix:\n";
    int secondRows = utility.getDimension();
    int secondColumns = utility.getDimension();
    if((firstRows != secondRows) || (firstColumns != secondColumns))
    {
        std::cout << "Invalid dimensions! dimension of first must be equal dimension of second.\n";
        return Matrix();
    }
    Matrix firstMatrix(firstRows, firstColumns);
    Matrix secondMatrix(secondRows, secondColumns);
    firstMatrix.setDimensions(firstRows, firstColumns);
    secondMatrix.setDimensions(secondRows, secondColumns);
    std::cout << "Enter elements for first matrix:\n";
    firstMatrix.matrixInputElements(firstMatrix, "firstMatrix");
    std::cout << "Enter elements for second matrix:\n";
    secondMatrix.matrixInputElements(secondMatrix, "secondMatrix");
    return firstMatrix+secondMatrix;
}

Matrix MatrixOperations::matrixMultiplication(MatrixUtility& utility) {
    std::cout << "Enter rows and columns for first matrix:\n";
    int firstRows = utility.getDimension();
    int firstColumns = utility.getDimension();
    std::cout << "Enter rows and columns for second matrix:\n";
    int secondRows = utility.getDimension();
    int secondColumns = utility.getDimension();
    if (firstColumns != secondRows) {
        std::cout << "Invalid dimensions! Columns of first must equal rows of second.\n";
        return Matrix();
    }
    Matrix firstMatrix(firstRows, firstColumns);
    Matrix secondMatrix(secondRows, secondColumns);
    firstMatrix.setDimensions(firstRows, firstColumns);
    secondMatrix.setDimensions(secondRows, secondColumns);
    std::cout << "Enter elements for first matrix:\n";
    firstMatrix.matrixInputElements(firstMatrix, "firstMatrix");
    std::cout << "Enter elements for second matrix:\n";
    secondMatrix.matrixInputElements(secondMatrix, "secondMatrix");
    return firstMatrix * secondMatrix;
}
