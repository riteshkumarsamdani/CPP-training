#ifndef ITRAFFIC_CONTROLLER_H
#define ITRAFFIC_CONTROLLER_H

class ITrafficLightController 
{
    public:
        virtual void start() = 0;
        virtual ~ITrafficLightController() = default;
};

#endif
