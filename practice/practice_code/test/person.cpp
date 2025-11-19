#include "Person.h"

void Person::drive()
{
    for(auto vehi : vehicles_)
    {
        std::cout << "drive : " << vehi->getName() << std::endl;
    }          
}

bool Person::deleteVehicle(std::string name)
{
    bool status = false;
    for(auto it = vehicles_.begin(); it != vehicles_.end(); ++it)
    {
        if((*it)->getName() == name)
        {
            delete *it;
            vehicles_.erase(it); 
            status = true;
            break;
        }
    }
    return status;
}


bool Person::addVehicle(IVehicle* vehi)
{
    bool success = false;
    for(auto ve : vehicles_)
    {
        if(ve->getName() == vehi->getName())
        {
            success = false;
            break;
        }
    }
    if(!success)
    {
        vehicles_.push_back(vehi);
        success = true;
    }
    return success;
}

Person::~Person()
{
    for(auto veh : vehicles_)
    {
        delete veh;
    }
}

Person::Person(std::vector<IVehicle*> vehicles) : vehicles_(vehicles) {};

