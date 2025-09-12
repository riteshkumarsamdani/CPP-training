#include "ArrayUtils.h"
#ifndef MATRIX_OPERATION_H
#define MATRIX_OPERATION_H

extern "C" void matrixOperations();
extern "C" double** matrixAddition(double** firstMatrix, double** secondMatrix, const Dimensions& dimensions);
extern "C" double** matrixMultiplication(double** firstMatrix, double** secondMatrix, const Dimensions& dimensions);

#endif
