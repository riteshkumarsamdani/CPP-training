#include "Lane.h"
#include "MockLogger.h"
#include <gtest/gtest.h>
#include <thread>
#include <chrono>

class LaneTest : public ::testing::Test
{
    protected:
        TrafficSignal signal;
        MockLogger logger;
        Lane lane{"North", &signal, &logger};
};

TEST_F(LaneTest, GivenLeft_When_ProcessRequestCalled_Then_ReturnTrue)
{
    bool status = lane.isSignalGreen("left");
    EXPECT_TRUE(status);
}

TEST_F(LaneTest, GivenGreenSignalMatchesLane_WhenProcessRequestCalled_ThenReturnsTrue)
{
    signal.currentGreenLane = "North";
    bool status = lane.isSignalGreen("straight");
    EXPECT_TRUE(status);
}

TEST_F(LaneTest, GivenGreenSignalDoesNotMatchLane_WhenProcessRequestCalled_ThenReturnsFalse)
{
    signal.currentGreenLane = "South";
    bool status = lane.isSignalGreen("straight");
    EXPECT_FALSE(status);
}
