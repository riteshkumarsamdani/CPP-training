#ifndef VEHICLE_H
#define VEHICLE_H

#include "IVehicle.h"

class Vehicle : public IVehicle
{
    std::string name_;
    public:
        std::string getName() override;
        Vehicle(std::string name);
};

#endif
