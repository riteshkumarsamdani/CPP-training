#ifndef LANE_H
#define LANE_H

#include "ILane.h"
#include "SharedState.h"
#include "ILogger.h"

class Lane : public ILane
{
    public:
        std::string name;
        SharedState* shared;
        ILogger* logger;
        std::pair<std::string, std::string> currentVehicle;
        bool hasVehicle = false;
        bool isProcessed = false;
        std::mutex vehicleMutex;
        std::condition_variable vehicleCV;
        std::condition_variable processedCV;

    public:
        Lane(const std::string& name, SharedState* shared, ILogger* logger);
        bool processVehicle(const std::string& vehicleId, const std::string& direction) override;
        void run() override;
        void assignVehicle(const std::string& carId, const std::string& direction) override;
        void waitUntilProcessed() override;

};

#endif
