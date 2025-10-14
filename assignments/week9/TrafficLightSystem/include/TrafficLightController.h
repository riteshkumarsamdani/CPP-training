#ifndef TRAFFIC_LIGHT_CONTROLLER_H
#define TRAFFIC_LIGHT_CONTROLLER_H

#include "SharedState.h"
#include "Logger.h"
#include "ITrafficLightController.h"
#include <vector>
#include <string>

class TrafficLightController : public ITrafficLightController 
{
    private:
        std::vector<std::string> laneOrder;
        SharedState* shared;
        ILogger* logger;

    public:
        TrafficLightController(SharedState* shared, ILogger* logger);
        void start() override;
};

#endif
