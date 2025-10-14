#include "TrafficSystem.h"
#include "Logger.h"

TrafficSystem::TrafficSystem() : shared(nullptr), logger(nullptr), controller(nullptr) {}

void TrafficSystem::initialize()
{
    shared = new SharedState();
    logger = new Logger();
    for (const auto& dir : {"North", "East", "South", "West"})
    {
        Lane* lane = new Lane(dir, shared, logger);
        lanes[dir] = lane;
        laneThreads.emplace_back([lane]() { lane->run(); }); 
    }
    controller = new TrafficLightController(shared, logger);
    controllerThread = std::thread([this]() { controller->start(); });
}

TrafficSystem::~TrafficSystem()
{
    if (controllerThread.joinable()) controllerThread.join();
    for (auto& thread : laneThreads)
    {
        if (thread.joinable()) thread.join();
    }
    for (auto& [_, lane] : lanes) delete lane;
    delete controller;
    delete logger;
    delete shared;
}

bool TrafficSystem::assignVehicleToLane(const std::string& laneName, const std::string& vehicleId, const std::string& direction) {
    bool assign = false;
    if (lanes.count(laneName)) 
    {
        lanes[laneName]->assignVehicle(vehicleId, direction);
        assign = true;
    }
    else
    {
        logger->log("Invalid lane: " + laneName);
    }
    return assign;
}

bool TrafficSystem::waitUntilProcessed(const std::string& laneName)
{
    bool wait = false;
    if (lanes.count(laneName)) {
        lanes[laneName]->waitUntilProcessed();
        wait = true;
    }
    return wait;
}
