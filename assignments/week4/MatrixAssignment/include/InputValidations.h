#include <iostream>
#ifndef INPUT_VALIDATIONS_H
#define INPUT_VALIDATIONS_H

class InputValidation
{
    public: 
        int validateDimension(const std::string&);
        double validateElement(const std::string&);
        double doubleMax();
        int intMax();
};

#endif
