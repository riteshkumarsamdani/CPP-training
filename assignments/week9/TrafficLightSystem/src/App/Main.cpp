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
    input.getUserInput("Enter your lane : ", userChoice);
    std::string userLane;
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
            std::cout << "Invalid Choice\n";
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
    input.getUserInput("Enter your direction in which you want to move : ", userChoice);
    std::string direction;
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
            std::cout << "Invalid Choice\n";
    }
    return direction;
}

int main()
{
    TrafficSystem system;
    InputHandler input;
    int vehicleCounter = 1;
    while (true)
    {
        try
        {
            std::string lane = getUserLane(input);
            while (lane.empty())
            {
                std::cout << "Please enter valid choice.\n";
                lane = getUserLane(input);
            }
            std::string direction = getUserDirection(input);
            while (direction.empty())
            {
                std::cout << "Please enter valid choice.\n";
                direction = getUserDirection(input);
            }
            std::string vehicleId = "vehicle" + std::to_string(vehicleCounter++);
            system.assignVehicleToLane(lane, vehicleId, direction);
            system.waitUntilProcessed(lane);
            std::cout << vehicleId << " processed from " << lane << " going " << direction << ".\n";
        } 
        catch (const std::exception& e)
        {
            std::cerr << "Unexpected error: " << e.what() << "\n";
        }
    }
    return 0;
}
