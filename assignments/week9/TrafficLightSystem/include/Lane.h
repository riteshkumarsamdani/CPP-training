#ifndef LANE_H
#define LANE_H

#include "ILane.h"
#include "TrafficSignal.h"
#include "Logger.h"

class Lane : public ILane 
{
    private:
        std::string name;
        TrafficSignal* signal;
        ILogger* logger;

    public:
        Lane(const std::string& name, TrafficSignal* signal, ILogger* logger);
        void waitForGreenSignal() override;
        bool isSignalGreen(const std::string& direction) override;
};

#endif
