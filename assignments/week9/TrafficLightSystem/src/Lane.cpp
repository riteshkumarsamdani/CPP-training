#include "Lane.h"
#include <thread>
#include <chrono>

Lane::Lane(const std::string& name, TrafficSignal* signal, ILogger* logger)
    : name(name), signal(signal), logger(logger) {}

bool Lane::isSignalGreen(const std::string& direction)
{
    bool canMove = false;
    if(direction == "left")
    {
        canMove = true;
    }
    else
    {
        std::unique_lock<std::mutex> lock(signal->laneMutex);
        canMove = signal->currentGreenLane == name;
    }
    return canMove;
}

void Lane::waitForGreenSignal()
{
    std::unique_lock<std::mutex> lock(signal->laneMutex);
    signal->signalChangeCV.wait(lock, [&] { return signal->currentGreenLane == name; });
}
