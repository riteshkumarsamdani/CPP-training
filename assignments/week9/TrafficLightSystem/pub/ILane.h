#ifndef ILANE_H
#define ILANE_H

#include <string>

class ILane 
{
    public:
        virtual ~ILane() = default;
        virtual void waitForGreenSignal() = 0;
        virtual bool isSignalGreen(const std::string& direction) = 0;
};

#endif
