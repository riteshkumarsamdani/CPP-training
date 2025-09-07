#include <iostream>
#ifndef INPUT_VALIDATIONS_H
#define INPUT_VALIDATIONS_H

class InputValidation
{
    public: 
        int validDimension(const std::string&);
        double validElement(const std::string&);
        double doubleMax();
        int intMax();
};

#endif