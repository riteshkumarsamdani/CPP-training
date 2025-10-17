#ifndef TRAFFIC_LIGHT_CONTROLLER_H
#define TRAFFIC_LIGHT_CONTROLLER_H

#include "TrafficSignal.h"
#include "Logger.h"
#include "ITrafficLightController.h"
#include <vector>
#include <string>

class TrafficLightController : public ITrafficLightController 
{
    private:
        std::vector<std::string> laneOrder;
        TrafficSignal* signal;
        ILogger* logger;
        bool run;
        int sleepDuration;

    public:
        TrafficLightController(TrafficSignal* signal, ILogger* logger, int sleepDuration);
        void start() override;
        void stop() override;
};

#endif
