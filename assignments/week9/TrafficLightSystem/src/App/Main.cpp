#include "TrafficSystem.h"
#include "InputHandler.h"
#include <string>
#include <algorithm>
#include <stdexcept>

void printLaneMenu()
{
    std::cout << "1. North\n";
    std::cout << "2. East\n";
    std::cout << "3. South\n";
    std::cout << "4. West\n";
}

std::string getUserLane(InputHandler& input)
{
    int userChoice;
    printLaneMenu();
    std::string userLane{};
    while(userLane.empty())
    {
        input.getUserInput("Enter your lane : ", userChoice);
        switch(userChoice)
        {
            case 1:
                userLane = "North";
                break;
            case 2:
                userLane = "East";
                break;
            case 3:
                userLane = "South";
                break;
            case 4:
                userLane = "West";
                break;
            default:
                userLane = "";
                std::cout << "Invalid Choice.\nPlease enter valid choice.\n";
        }
    }
    return userLane;
}

void printDirectionMenu()
{
    std::cout << "1. straight\n";
    std::cout << "2. left\n";
    std::cout << "3. right\n";
}

std::string getUserDirection(InputHandler& input)
{
    int userChoice;
    printDirectionMenu();
    std::string direction{};
    while(direction.empty())
    {
        input.getUserInput("Enter your direction in which you want to move : ", userChoice);
        switch(userChoice)
        {
            case 1:
                direction = "straight";
                break;
            case 2:
                direction = "left";
                break;
            case 3:
                direction = "right";
                break;
            default:
                direction = "";
                std::cout << "Invalid Choice.\nPlease enter valid choice.\n";
        }
    }
    return direction;
}

int main()
{
    InputHandler input;
    std::string filePath = "/home/riteshkgs/Desktop/cpprogramming/CPP-training/assignments/week9/Output/output.txt";
    ILogger* logger = new Logger(filePath);
    TrafficSignal* signal = new TrafficSignal();
    ITrafficLightController* controller = new TrafficLightController(signal, logger, 10);
    std::unordered_map<std::string, ILane*> lanes;
    for (const auto& directions : {"North", "East", "South", "West"})
    {
        ILane* lane = new Lane(directions, signal, logger);
        lanes[directions] = lane;
    }
    TrafficSystem* system = new TrafficSystem(signal, logger, controller, lanes);
    bool close = false;
    while (!close)
    {
        int userChoice;
        std::cout << "1. generate process request\n";
        std::cout << "2. close simulation\n";
        input.getUserInput("Enter your choice : ", userChoice);
        switch(userChoice)
        {
            case 1:
            {
                std::string lane = getUserLane(input);
                std::string direction = getUserDirection(input);
                system->processRequest(lane,direction);
                break;
            }
            case 2:
            {
                close = true;
                break;
            }
            default:
                std::cout << "Invalid choice\n";
        }
    }
    delete system;
    delete logger;
    delete signal;
    delete controller;
    for (auto& [direction, lane] : lanes) delete lane;
    return 0;
}
