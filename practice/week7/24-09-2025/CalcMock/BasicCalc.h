#ifndef BASICCALC_H
#define BASICCALC_H
#include "ICalc.h"

class BasicCalc : public ICalc {
public:
    int add(int a, int b) override;
    int sub(int a, int b) override;
    int multiply(int a, int b) override;
    int division(int a, int b) override;
};

#endif
