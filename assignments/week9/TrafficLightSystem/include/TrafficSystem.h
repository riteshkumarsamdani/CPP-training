#ifndef TRAFFIC_SYSTEM_H
#define TRAFFIC_SYSTEM_H

#include <unordered_map>
#include <thread>
#include "Lane.h"
#include "TrafficLightController.h"
#include "TrafficSignal.h"
#include "Logger.h"

class TrafficSystem
{
    private:
        std::unordered_map<std::string, ILane*> lanes;
        std::thread controllerThread;
        TrafficSignal* signal;
        ILogger* logger;
        ITrafficLightController* controller;

    public:
        TrafficSystem(TrafficSignal* signal, ILogger* logger, ITrafficLightController* controller, std::unordered_map<std::string, ILane*> lanes);
        ~TrafficSystem();
        bool processRequest(const std::string& laneName, const std::string& direction);
};

#endif
