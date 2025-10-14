#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <thread>
#include <chrono>
#include "Lane.h"
#include "SharedState.h"
#include "MockLogger.h"

class LaneTest : public ::testing::Test 
{
protected:
    SharedState* shared;
    MockLogger* logger;
    Lane* lane;

    void SetUp() override 
    {
        shared = new SharedState();
        logger = new MockLogger();
        lane = new Lane("North", shared, logger);
    }

    void TearDown() override 
    {
        delete lane;
        delete logger;
        delete shared;
    }
};

TEST_F(LaneTest, Given_LeftDirection_When_ProcessVehicleCalled_Then_LogsTurnAndReturnsTrue)
{
    std::string vehicleId = "vehicle1";
    std::string direction = "left";
    EXPECT_CALL(*logger, log("Car vehicle1 from North turns LEFT"));
    EXPECT_CALL(*logger, log("Car vehicle1 from North passed"));

    bool result = lane->processVehicle(vehicleId, direction);

    EXPECT_TRUE(result);
}

TEST_F(LaneTest, Given_StraightDirectionAndGreenSignal_When_ProcessVehicleCalled_Then_LogsProceedAndReturnsTrue)
{
    std::string vehicleId = "vehicle2";
    std::string direction = "straight";
    shared->currentGreenLane = "North";
    EXPECT_CALL(*logger, log("Car vehicle2 from North going straight proceeds"));
    EXPECT_CALL(*logger, log("Car vehicle2 from North passed"));

    bool result = lane->processVehicle(vehicleId, direction);

    EXPECT_TRUE(result);
}

TEST_F(LaneTest, Given_VehicleDetails_When_AssignVehicleCalled_Then_StoresVehicleCorrectly)
{
    std::string vehicleId = "vehicle3";
    std::string direction = "right";

    lane->assignVehicle(vehicleId, direction);

    EXPECT_EQ(lane->currentVehicle.first, vehicleId);
    EXPECT_EQ(lane->currentVehicle.second, direction);
    EXPECT_TRUE(lane->hasVehicle);
    EXPECT_FALSE(lane->isProcessed);
}

TEST_F(LaneTest, Given_AssignedVehicle_When_WaitUntilProcessedCalled_Then_WaitsUntilProcessedIsTrue)
{
    std::string vehicleId = "vehicle4";
    std::string direction = "left";

    lane->assignVehicle(vehicleId, direction);

    std::thread runner([&]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        lane->processVehicle(vehicleId, direction);
        lane->isProcessed = true;
        lane->processedCV.notify_one();
    });

    lane->waitUntilProcessed();

    EXPECT_TRUE(lane->isProcessed);
    runner.join();
}

TEST_F(LaneTest, Given_AssignedVehicle_When_RunCalledInThread_Then_ProcessesVehicleAndSetsProcessedTrue) 
{
    std::string vehicleId = "vehicle5";
    std::string direction = "left";
    EXPECT_CALL(*logger, log("Car vehicle5 from North turns LEFT"));
    EXPECT_CALL(*logger, log("Car vehicle5 from North passed"));

    std::thread laneThread([&]() {
        lane->run();
    });

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    lane->assignVehicle(vehicleId, direction);
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    EXPECT_TRUE(lane->isProcessed);
    laneThread.detach(); 
}
