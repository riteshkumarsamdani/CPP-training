#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

struct Dimensions
{
    int firstRows;
    int secondRows;
    int firstColumns;
    int secondColumns;
};

struct Arrays
{
    double** firstMatrix {nullptr};
    double** secondMatrix {nullptr};
    double** outputMatrix {nullptr};
};

extern "C" double** createArray(int rows, int columns, bool isUserInput);
extern "C" void deleteArray(double** matrix, int rows);
extern "C" void printArray(double** matrix,int rows, int columns);

#endif
