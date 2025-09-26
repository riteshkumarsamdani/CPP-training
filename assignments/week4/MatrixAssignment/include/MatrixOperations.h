#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include "Matrix.h"
#include "MatrixUtility.h"

class MatrixOperations 
{
    public:
        Matrix matrixAddition(MatrixUtility& utility);
        Matrix matrixMultiplication(MatrixUtility& utility);
        Matrix createMatrix(MatrixUtility& utility);
};

#endif
