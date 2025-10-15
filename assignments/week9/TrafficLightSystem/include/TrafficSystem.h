#ifndef TRAFFIC_SYSTEM_H
#define TRAFFIC_SYSTEM_H

#include <unordered_map>
#include <thread>
#include "Lane.h"
#include "TrafficLightController.h"
#include "SharedState.h"
#include "Logger.h"

class TrafficSystem
{
    private:
        std::unordered_map<std::string, Lane*> lanes;
        std::thread controllerThread;
        SharedState* shared;
        ILogger* logger;
        TrafficLightController* controller;
        std::vector<std::thread> laneThreads;
    public:
        TrafficSystem();
        ~TrafficSystem();
        bool assignVehicleToLane(const std::string& laneName, const std::string& vehicleId, const std::string& direction);
        bool waitUntilProcessed(const std::string& laneName); 
};

#endif
