#include "TrafficLightController.h"
#include <thread>
#include <chrono>

TrafficLightController::TrafficLightController(SharedState* shared, ILogger* logger)
    : shared(shared), logger(logger), laneOrder({"North", "East", "South", "West"}) {}

void TrafficLightController::start()
{
    while (true)
    {
        for (const auto& lane : laneOrder)
        {
            {
                std::lock_guard<std::mutex> lock(shared->laneMutex);
                shared->currentGreenLane = lane;
                logger->log("Signal GREEN at " + lane);
            }
            shared->cv.notify_all();
            std::this_thread::sleep_for(std::chrono::seconds(10));
            logger->log("Signal RED at " + lane);
        }
    }
}
