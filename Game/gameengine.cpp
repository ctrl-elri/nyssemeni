#include "gameengine.hh"
#include "graphics/simplemainwindow.hh"


gameEngine::gameEngine()
{

}

void gameEngine::initGame()
{
   city_ = Interface::createGame();

   CourseSide::Logic* logic = new CourseSide::Logic;
   logic->fileConfig();
   logic->setTime(16,0);
   logic->takeCity(city_);
   logic->finalizeGameStart();

}
