#include "vehicle.h"

Vehicle::Vehicle()
{

}


Interface::Location Vehicle::giveLocation() const
{
}

void Vehicle::move(Interface::Location loc)
{
    location = loc;
}

bool Vehicle::isRemoved() const
{
}

void Vehicle::remove()
{
}

std::string Vehicle::getName() const
{
}

std::vector<std::shared_ptr<Interface::IPassenger> > Vehicle::getPassengers() const
{
}

void Vehicle::addPassenger(std::shared_ptr<Interface::IPassenger> passenger)
{
}

void Vehicle::removePassenger(std::shared_ptr<Interface::IPassenger> passenger)
{
}
