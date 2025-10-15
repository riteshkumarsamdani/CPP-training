#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "TrafficSystem.h"
#include "MockLane.h"
#include "MockLogger.h"

class TrafficSystemTest : public ::testing::Test 
{
    protected:
        TrafficSystem system;
        SharedState shared;
        MockLogger logger;
        MockLane mockLane;
};

TEST_F(TrafficSystemTest, Given_ValidLane_When_AssignVehicleToLaneCalled_Then_ReturnsTrue)
{
    std::string lane = "North";
    std::string vehicleId = "vehicle1";
    std::string direction = "left";
    bool result = system.assignVehicleToLane(lane, vehicleId, direction);
    EXPECT_TRUE(result);
}

TEST_F(TrafficSystemTest, Given_InvalidLane_When_AssignVehicleToLaneCalled_Then_ReturnsFalse) 
{
    std::string lane = "InvalidLane";
    std::string vehicleId = "vehicle2";
    std::string direction = "right";
    EXPECT_CALL(logger, log("Invalid lane: InvalidLane"));
    bool result = system.assignVehicleToLane(lane, vehicleId, direction);
    EXPECT_FALSE(result);
}

TEST_F(TrafficSystemTest, Given_ValidLane_When_WaitUntilProcessedCalled_Then_ReturnsTrue)
{
    std::string lane = "North";
    bool result = system.waitUntilProcessed(lane);
    EXPECT_TRUE(result);
}

TEST_F(TrafficSystemTest, Given_InvalidLane_When_WaitUntilProcessedCalled_Then_ReturnsFalse)
{
    std::string lane = "InvalidLane";
    bool result = system.waitUntilProcessed(lane);
    EXPECT_FALSE(result);
}
