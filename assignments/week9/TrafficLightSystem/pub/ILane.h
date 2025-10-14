#ifndef ILANE_H
#define ILANE_H

#include <string>

class ILane 
{
    public:
        virtual bool processVehicle(const std::string& vehicleId, const std::string& direction) = 0;
        virtual void run() = 0;
        virtual void assignVehicle(const std::string& carId, const std::string& direction) = 0;
        virtual void waitUntilProcessed() = 0;
        virtual ~ILane() = default;
};

#endif
