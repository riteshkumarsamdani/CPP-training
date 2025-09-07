#include "InputValidations.h"
#ifndef Matrix_Utility_H
#define Matrix_Utility_H

class MatrixUtility : public InputValidation
{
    private:
        char choice{};
    public:
        char getChoice();
        void setChoice(const char& choice);
        int getDimension();
        double inputElement(int row, int column, const std::string& matrixName);
};

#endif
