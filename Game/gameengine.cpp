#include "gameengine.hh"
#include "graphics/simplemainwindow.hh"
#include "interfaces/istop.hh"
#include "actors/stop.hh"

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

   logic->addNewBuses();

   //std::shared_ptr<CourseSide::Stop> stop (new CourseSide::Stop());
   //city->addStop();

}
