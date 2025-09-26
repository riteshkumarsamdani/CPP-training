#include "InputValidations.h"
#ifndef Matrix_Utility_H
#define Matrix_Utility_H

class MatrixUtility : public InputValidation
{
    private:
        char userChoice{};
    public:
        char getUserChoice();
        void setUserChoice(const char userChoice);
        int getDimension();
        double inputElement(int row, int column);
};

#endif
