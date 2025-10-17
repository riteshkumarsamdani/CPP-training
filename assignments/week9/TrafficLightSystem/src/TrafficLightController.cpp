#include "TrafficLightController.h"
#include <thread>
#include <chrono>

TrafficLightController::TrafficLightController(TrafficSignal* signal, ILogger* logger, int sleepDuration)
    : signal(signal), logger(logger), laneOrder({"North", "East", "South", "West"}), run(false), sleepDuration(sleepDuration) {}

void TrafficLightController::stop()
{
    run = false;
}

void TrafficLightController::start()
{
    run = true;
    while (run)
    {
        for (const auto& lane : laneOrder)
        {
            {
                std::lock_guard<std::mutex> lock(signal->laneMutex);
                signal->currentGreenLane = lane;
                logger->logToFile("Signal GREEN at " + lane);
            }
            signal->signalChangeCV.notify_all();
            std::this_thread::sleep_for(std::chrono::seconds(sleepDuration));
            logger->logToFile("Signal RED at " + lane);
            if(!run) break;
        }
    }
}
