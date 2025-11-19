#include "Person.h"

int main()
{
    IVehicle* vehicle1 = new Vehicle("toyota");
    IVehicle* vehicle2 = new Vehicle("Ferrari");
    Person person({vehicle1, vehicle2});
    person.drive();
    person.deleteVehicle("toyota");
    person.drive();
    return 0;
}