#include "gameengine.hh"

gameEngine::gameEngine()
{

}

void gameEngine::initGame()
{

   city_ = Interface::createGame();

   logic_ = new CourseSide::Logic;

   logic_->fileConfig();
   logic_->takeCity(city_);

   logic_->finalizeGameStart();


}

void gameEngine::createPlayer()
{
   player_ = new Player(city_);
}



