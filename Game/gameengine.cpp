#include "gameengine.hh"
#include "graphics/simplemainwindow.hh"

gameEngine::gameEngine()
{

}

void gameEngine::initGame()
{
   std::shared_ptr<Interface::ICity> city;
   city = Interface::createGame();

   CourseSide::Logic* logic = new CourseSide::Logic;
   logic->takeCity(city);
   logic->fileConfig();
   logic->setTime(16,0);
   logic->finalizeGameStart();

}
