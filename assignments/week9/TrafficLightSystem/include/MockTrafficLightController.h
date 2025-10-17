#ifndef MOCK_TRAFFIC_LIGHT_CONTROLLER_H
#define MOCK_TRAFFIC_LIGHT_CONTROLLER_H

#include <gmock/gmock.h>
#include "ITrafficLightController.h"

class MockTrafficLightController : public ITrafficLightController
{
    public:
        MOCK_METHOD(void, start, (), (override));
        MOCK_METHOD(void, stop, (), (override));
};

#endif
