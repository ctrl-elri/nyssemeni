#ifndef ACTOR_HH
#define ACTOR_HH

#include "interfaces/iactor.hh"


class Actor : public Interface::IActor
{
public:
    Actor();

    // IActor interface
public:
    Interface::Location giveLocation() const;
    void move(Interface::Location loc);
    bool isRemoved() const;
    void remove();

private:
    Interface::Location location;
};

#endif // ACTOR_HH
