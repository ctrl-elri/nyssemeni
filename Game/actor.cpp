#include "actor.hh"

Actor::Actor()
{

}


Interface::Location Actor::giveLocation() const
{
    return location;
}

void Actor::move(Interface::Location loc)
{
    location = loc;
}

bool Actor::isRemoved() const
{
    return  0;
}

void Actor::remove()
{
}
