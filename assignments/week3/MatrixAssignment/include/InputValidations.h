#include <string>
#ifndef INPUT_VALIDATIONS_H
#define INPUT_VALIDATIONS_H

extern "C" int validateDimension(const std::string& userInput);
extern "C" double validateElement(const std::string& userInput);
extern "C" double doubleMax();
extern "C" int intMax();

#endif
