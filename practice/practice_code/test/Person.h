#ifndef PERSON_H
#define PERSON_H

#include "Vehicle.h"
#include <vector>
#include <iostream>

class Person
{
    private:
        std::vector<IVehicle*> vehicles_;
    public:
        void drive();
        bool deleteVehicle(std::string name);
        bool addVehicle(IVehicle* ve);
        Person(std::vector<IVehicle*> vehicles);
        ~Person();
};

#endif
