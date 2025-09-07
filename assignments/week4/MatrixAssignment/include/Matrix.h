# include "MatrixUtility.h"
#ifndef Matrix_H
#define Matrix_H

class Matrix : public MatrixUtility
{
    private:
        int columns{};
        int rows{};
        double** matrix;
    public:
        Matrix(int, int);
        ~Matrix();
        Matrix();
        void displayMatrix(const std::string&) const;
        const int& getRows() const;
        const int& getColumns() const;
        void setDimensions(int& rows, int& colums);
        double** matrixInputElements(Matrix&, const std::string& matrixName);
        Matrix operator*(Matrix&);
        Matrix operator+(Matrix&);
};

#endif
