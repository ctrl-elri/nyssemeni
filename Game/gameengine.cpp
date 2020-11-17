#include "gameengine.hh"

gameEngine::gameEngine()
{

}

void gameEngine::initGame()
{
   std::shared_ptr<Interface::ICity> city;
   city = Interface::createGame();

   CourseSide::Logic* logic = new CourseSide::Logic;
   logic->fileConfig();
   logic->takeCity(city);
   logic->setTime(16,0);
   logic->finalizeGameStart();

}
