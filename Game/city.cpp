#include "city.hh"

City::City()
{

}

City::~City()
{

}


void City::setBackground(QImage &basicbackground, QImage &bigbackground)
{
    mainW_ = new MainWindow;
    mainW_->setPicture(basicbackground);

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
    mainW_->addActor(stopLoc.giveX(), 500-stopLoc.giveY(), 600);
    stops_.push_back(stop);
}

void City::startGame()
{
    gameIsOver_ = false;

    //ui_->addActor(1,1);
    mainW_->show();

}

void City::addActor(std::shared_ptr<Interface::IActor> newactor)
{
    Interface::Location actorLoc = newactor->giveLocation();

    if (dynamic_cast<CourseSide::Passenger*>(newactor.get()) != 0){
        mainW_->getActor(newactor);
        mainW_->addActor(actorLoc.giveX()-5, 500-actorLoc.giveY()-5, 400);
    } else if (dynamic_cast<CourseSide::Nysse*>(newactor.get()) != 0){
        mainW_->getActor(newactor);
        mainW_->addActor(actorLoc.giveX()-5, 500-actorLoc.giveY()-5, 1000);
    } else {
        return;
    }

    mainW_->addToMap();
    actorsInGame_.push_back(newactor);
}

void City::removeActor(std::shared_ptr<Interface::IActor> actor)
{
    for (auto a: actorsInGame_){
        if (a == actor){
            actorsInGame_.erase((std::remove(actorsInGame_.begin(), actorsInGame_.end(), actor), actorsInGame_.end()));
            actorsRemoved_.push_back(actor);
            mainW_->removeActorItem(actor);
        }
    }
}

void City::actorRemoved(std::shared_ptr<Interface::IActor> actor)
{
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
    mainW_->moveActorItem(actor);
}

std::vector<std::shared_ptr<Interface::IActor> > City::getNearbyActors(Interface::Location loc) const
{

}

bool City::isGameOver() const
{
    return gameIsOver_;
}



