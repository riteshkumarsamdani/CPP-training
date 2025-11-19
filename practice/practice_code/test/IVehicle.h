#ifndef IVEHICLE_H
#define IVEHICLE_H

#include <string>

class IVehicle
{
    public:
        virtual std::string getName() = 0;
};

#endif
