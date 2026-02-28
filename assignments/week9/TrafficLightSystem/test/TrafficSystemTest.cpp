#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>
#include "TrafficSystem.h"
#include "MockLane.h"
#include "MockLogger.h"
#include "MockTrafficLightController.h"

class TrafficSystemTest : public ::testing::Test 
{
    protected:
        TrafficSignal signal;
        MockLogger logger;
        MockTrafficLightController controller;
        TrafficSystem* system;
        std::unordered_map<std::string, ILane*> lanes;
        std::unordered_map<std::string, MockLane*> mockLanes;

        void SetUp() override
        {
            for (const auto& directions : {"North", "East", "South", "West"})
            {
                auto* lane = new MockLane();
                lanes[directions] = lane;
                mockLanes[directions] = lane;
            }
            system = new TrafficSystem(&signal, &logger, &controller, lanes);
        }

        void TearDown() override
        {
            for (auto& [direction, lane] : lanes) delete lane;
            delete system;
        }
};

TEST_F(TrafficSystemTest, Given_ValidLane_When_ProcessRequestCalled_Then_ReturnsTrue)
{
    std::string lane = "North";
    std::string direction = "straight";
    EXPECT_CALL(*mockLanes[lane], isSignalGreen(direction)).WillOnce(::testing::Return(true));
    EXPECT_CALL(logger, log("you can proceed from North to straight"));
    bool result = system->processRequest(lane, direction);
    EXPECT_TRUE(result);
}

TEST_F(TrafficSystemTest, Given_ValidLane_When_ProcessRequestCalled_With_WaitCondition_Then_ReturnsTrue)
{
    std::string lane = "South";
    std::string direction = "straight";
    EXPECT_CALL(*mockLanes[lane], isSignalGreen(direction)).WillOnce(::testing::Return(false));
    EXPECT_CALL(*mockLanes[lane], waitForGreenSignal()).WillOnce(::testing::Return());
    EXPECT_CALL(logger, log("wait for signal to green"));
    EXPECT_CALL(logger, log("you can proceed from South to straight"));
    bool result = system->processRequest(lane, direction);
    EXPECT_TRUE(result);
}

TEST_F(TrafficSystemTest, Given_InvalidLane_When_ProcessRequestCalled_Then_ReturnsFalse) 
{
    std::string lane = "InvalidLane";
    std::string direction = "right";
    EXPECT_CALL(logger, log("Invalid lane: InvalidLane"));
    bool result = system->processRequest(lane, direction);
    EXPECT_FALSE(result);
}
