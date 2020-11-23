#include "gameengine.hh"

gameEngine::gameEngine()
{

}

void gameEngine::initGame()
{

   city_ = Interface::createGame();

   logic_ = new CourseSide::Logic;

   logic_->fileConfig();

   //logic_->setTime(16,0);
   logic_->takeCity(city_);
   logic_->finalizeGameStart();


}



