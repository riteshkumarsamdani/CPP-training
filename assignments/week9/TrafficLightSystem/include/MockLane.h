#ifndef MOCK_LANE_H
#define MOCK_LANE_H

#include "ILane.h"
#include <gmock/gmock.h>

class MockLane : public ILane
{
    public:
        MOCK_METHOD(bool, processVehicle, (const std::string& vehicleId, const std::string& direction), (override));
        MOCK_METHOD(void, run, (), (override));
        MOCK_METHOD(void, assignVehicle, (const std::string& carId, const std::string& direction), (override));
        MOCK_METHOD(void, waitUntilProcessed, (), (override));
};

#endif
