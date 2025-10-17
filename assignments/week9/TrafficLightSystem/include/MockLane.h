#ifndef MOCK_LANE_H
#define MOCK_LANE_H

#include "ILane.h"
#include <gmock/gmock.h>

class MockLane : public ILane
{
    public:
        MOCK_METHOD(bool, isSignalGreen, (const std::string& direction), (override));
        MOCK_METHOD(void, waitForGreenSignal, (), (override));
};

#endif
