#ifndef GAMEENGINE_HH
#define GAMEENGINE_HH

#include "creategame.hh"
#include "core/logic.hh"
#include "city.hh"
#include "interfaces/istop.hh"
#include "actors/stop.hh"

class gameEngine
{
public:
    gameEngine();
    ~gameEngine();

    void initGame();

private:
    std::shared_ptr<Interface::ICity> city_;
    CourseSide::Logic *logic_;

};

#endif // GAMEENGINE_HH
