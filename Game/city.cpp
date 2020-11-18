#include "city.hh"

City::City()//:Interface::ICity()
{
    
}

City::~City()
{

}

void City::setBackground(QImage &basicbackground, QImage &bigbackground)
{
   CourseSide::SimpleMainWindow* ui = new CourseSide::SimpleMainWindow;
   ui->setPicture(basicbackground);
}

void City::setClock(QTime clock)
{
   if (clock.isValid() == true) {
       time_ = clock;
   }

   else {
       // Virhe, jos aika on virheellinen
   }
}

void City::addStop(std::shared_ptr<Interface::IStop> stop)
{
    ;
}

void City::startGame()
{
    gameIsOver_ = false;
}

void City::addActor(std::shared_ptr<Interface::IActor> newactor)
{
    actors_.push_back(newactor);
}

void City::removeActor(std::shared_ptr<Interface::IActor> actor)
{

}

void City::actorRemoved(std::shared_ptr<Interface::IActor> actor)
{

}

bool City::findActor(std::shared_ptr<Interface::IActor> actor) const
{

}

void City::actorMoved(std::shared_ptr<Interface::IActor> actor)
{

}

std::vector<std::shared_ptr<Interface::IActor> > City::getNearbyActors(Interface::Location loc) const
{

}

bool City::isGameOver() const
{
    return gameIsOver_;
}



