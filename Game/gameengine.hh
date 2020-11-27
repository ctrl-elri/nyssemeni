#ifndef GAMEENGINE_HH
#define GAMEENGINE_HH

#include "creategame.hh"
#include "core/logic.hh"
#include "player.hh"

class gameEngine
{
public:
    gameEngine();
    ~gameEngine();

    void initGame();

    void createPlayer();


private:
    std::shared_ptr<Interface::ICity> city_;
    CourseSide::Logic *logic_;
    Player* player_;


};

#endif // GAMEENGINE_HH
