#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <thread>
#include <chrono>
#include "TrafficLightController.h"
#include "SharedState.h"
#include "MockLogger.h"

class TrafficLightControllerTest : public ::testing::Test
{
    protected:
        SharedState shared;
        MockLogger logger;
        TrafficLightController* controller;
    
        void SetUp() override
        {
            controller = new TrafficLightController(&shared, &logger);
        }
    
        void TearDown() override
        {
            delete controller;
        }
};

TEST_F(TrafficLightControllerTest, Given_ControllerStarted_When_ThreadRunsBriefly_Then_SetsCurrentGreenLaneToNorth) 
{
    EXPECT_CALL(logger, log(::testing::_)).Times(::testing::AtLeast(1));

    std::thread t([&]() { controller->start(); });
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    t.detach();

    EXPECT_EQ(shared.currentGreenLane, "North");
}
