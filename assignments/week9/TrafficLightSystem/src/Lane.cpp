#include "Lane.h"
#include <thread>
#include <chrono>

Lane::Lane(const std::string& name, SharedState* shared, ILogger* logger)
    : name(name), shared(shared), logger(logger) {}

void Lane::run()
{
    while (true)
    {
        std::unique_lock<std::mutex> lock(vehicleMutex);
        vehicleCV.wait(lock, [&] { return hasVehicle; });
        processVehicle(currentVehicle.first, currentVehicle.second);
        hasVehicle = false;
        isProcessed = true;
        processedCV.notify_one();
    }
}

void Lane::assignVehicle(const std::string& carId, const std::string& direction)
{
    std::lock_guard<std::mutex> lock(vehicleMutex);
    currentVehicle = {carId, direction};
    hasVehicle = true;
    isProcessed = false;
    vehicleCV.notify_one();
}

bool Lane::processVehicle(const std::string& carId, const std::string& direction) 
{
    bool isVehicleProcessed = false;
    try
    {
        if (direction == "left") 
        {
            logger->log("Car " + carId + " from " + name + " turns LEFT");
            logger->log("Car " + carId + " from " + name + " passed");
            isVehicleProcessed = true;
        }
        else
        {
            std::unique_lock<std::mutex> lock(shared->laneMutex);
            shared->cv.wait(lock, [&] { return shared->currentGreenLane == name; });
            logger->log("Car " + carId + " from " + name + " going " + direction + " proceeds");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            logger->log("Car " + carId + " from " + name + " passed");
            isVehicleProcessed = true;
        }
    } 
    catch (const std::exception& e) 
    {
        logger->log("Exception in " + name + ": " + e.what());
    }
    return isVehicleProcessed;
}

void Lane::waitUntilProcessed()
{
    std::unique_lock<std::mutex> lock(vehicleMutex);
    processedCV.wait(lock, [&] { return isProcessed; });
}
