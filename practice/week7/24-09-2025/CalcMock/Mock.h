#ifndef MOCKCALC_H
#define MOCKCALC_H

#include <gmock/gmock.h>
#include "ICalc.h"

class MockCalc : public ICalc {
public:
    MOCK_METHOD(int, add, (int, int), (override));
    MOCK_METHOD(int, sub, (int, int), (override));
    MOCK_METHOD(int, multiply, (int, int), (override));
    MOCK_METHOD(int, division, (int, int), (override));
};

#endif
