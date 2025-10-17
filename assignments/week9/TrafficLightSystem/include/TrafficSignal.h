#ifndef TRAFFIC_SIGNAL_H
#define TRAFFIC_SIGNAL_H

#include <string>
#include <mutex>
#include <condition_variable>

struct TrafficSignal
{
    
    std::string currentGreenLane;
    std::mutex laneMutex;
    std::condition_variable signalChangeCV;
};

#endif
