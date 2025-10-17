#include "TrafficSystem.h"
#include "Logger.h"

TrafficSystem::TrafficSystem(TrafficSignal* signal, ILogger* logger, ITrafficLightController* controller, std::unordered_map<std::string, ILane*> lanes)
    : signal(signal), logger(logger), controller(controller), lanes(lanes)
{
    controllerThread = std::thread([controller]() { controller->start(); });
}

bool TrafficSystem::processRequest(const std::string& laneName, const std::string& direction)
{
    bool processed = false;
    if (lanes.count(laneName))
    {
        bool canMove = lanes[laneName]->isSignalGreen(direction);
        if(canMove)
        {
            logger->log("you can proceed from " + laneName + " to " + direction);
            processed = true;
        }
        else
        {
            logger->log("wait for signal to green");
            lanes[laneName]->waitForGreenSignal();
            logger->log("you can proceed from " + laneName + " to " + direction);
            processed = true;
        }
    }
    else
    {
        logger->log("Invalid lane: " + laneName);
        processed = false;
    }
    return processed;
}

TrafficSystem::~TrafficSystem()
{
    controller->stop();
    if (controllerThread.joinable()) controllerThread.join();
}
