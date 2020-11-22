#ifndef GAMEENGINE_HH
#define GAMEENGINE_HH

#include "creategame.hh"
#include "core/logic.hh"
#include "mainwindow.hh"
#include "city.hh"

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
