#include "city.hh"

City::City()
{

}

City::~City()
{

}


void City::setBackground(QImage &basicbackground, QImage &bigbackground)
{
    ui_ = new MainWindow;
    ui_->setPicture(basicbackground);

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
    Interface::Location stopLoc = stop->getLocation();
    ui_->addActor(stopLoc.giveX(), 500-stopLoc.giveY(), 600);
    stops_.push_back(stop);
}

void City::startGame()
{
    gameIsOver_ = false;

    //ui_->addActor(1,1);
    ui_->show();

}

void City::addActor(std::shared_ptr<Interface::IActor> newactor)
{
    Interface::Location actorLoc = newactor->giveLocation();
    ui_->getActor(newactor);
    ui_->addActor(actorLoc.giveX(), 500-actorLoc.giveY(), 400);
    ui_->addToMap();
    actorsInGame_.push_back(newactor);
}

void City::removeActor(std::shared_ptr<Interface::IActor> actor)
{
    for (auto a: actorsInGame_){
        if (a == actor){
            ;
        }
    }
}

void City::actorRemoved(std::shared_ptr<Interface::IActor> actor)
{
    actorsRemoved_.push_back(actor);
}

bool City::findActor(std::shared_ptr<Interface::IActor> actor) const
{
    for (auto a: actorsInGame_){
        if (a == actor){
            return true;
        }
    }

    return false;
}

void City::actorMoved(std::shared_ptr<Interface::IActor> actor)
{
    ui_->moveActorItem(actor);
}

std::vector<std::shared_ptr<Interface::IActor> > City::getNearbyActors(Interface::Location loc) const
{

}

bool City::isGameOver() const
{
    return gameIsOver_;
}



