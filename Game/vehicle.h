#ifndef VEHICLE_H
#define VEHICLE_H

#include "interfaces/ivehicle.hh"


class Vehicle: public Interface::IVehicle
{
public:
    Vehicle();

    // IActor interface
public:
    Interface::Location giveLocation() const;
    void move(Interface::Location loc);
    bool isRemoved() const;
    void remove();

    // IVehicle interface
public:
    std::string getName() const;
    std::vector<std::shared_ptr<Interface::IPassenger> > getPassengers() const;
    void addPassenger(std::shared_ptr<Interface::IPassenger> passenger);
    void removePassenger(std::shared_ptr<Interface::IPassenger> passenger);
private:
    Interface::Location location;
};

#endif // VEHICLE_H
