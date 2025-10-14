#ifndef SHARED_STATE_H
#define SHARED_STATE_H

#include <string>
#include <mutex>
#include <condition_variable>

struct SharedState 
{
    std::string currentGreenLane;
    std::mutex laneMutex;
    std::condition_variable cv;
};

#endif
