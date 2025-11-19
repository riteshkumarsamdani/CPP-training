#include "Vehicle.h"

Vehicle::Vehicle(std::string name) : name_(name){}

std::string Vehicle::getName()
{
    return name_;
}
