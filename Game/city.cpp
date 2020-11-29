#include "city.hh"

#include <QDebug>

City::City()
{
}

City::~City()
{

}

void City::setMainWindow(MainWindow* window)
{
    mainW_ = window;
    connect(mainW_, SIGNAL(exitFromMainwindow()), this, SLOT(exitGame()));
}


void City::setBackground(QImage &basicbackground, QImage &bigbackground)
{
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
    mainW_->addActor(stopLoc.giveX(), 500-stopLoc.giveY(), STOP_TYPE);
    stops_.push_back(stop);
}

void City::startGame()
{
    gameIsOver_ = false;

    // Adds players to the game
    int players = amountOfPlayers_;
    while (players != 0) {
        addPlayer();
        players = players - 1;
    }

    mainW_->setStartingPlayer();
    mainW_->show();

}

void City::addActor(std::shared_ptr<Interface::IActor> newactor)
{
    Interface::Location actorLoc = newactor->giveLocation();

    if (dynamic_cast<CourseSide::Passenger*>(newactor.get()) != 0){
        mainW_->setActor(newactor);
        mainW_->addActor(actorLoc.giveX()-5, 500-actorLoc.giveY()-5, PASSENGER_TYPE);
    } else if (dynamic_cast<CourseSide::Nysse*>(newactor.get()) != 0){
        mainW_->setActor(newactor);
        mainW_->addActor(actorLoc.giveX()-5, 500-actorLoc.giveY()-5, NYSSE_TYPE);
        nysses_.push_back(newactor);
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
           actor->remove();
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
    std::vector<std::shared_ptr<Interface::IActor>> nearbyActors;
    int limit = 45;

    for (auto b: nysses_){
        if (b->giveLocation().isClose(loc, limit) == true){
            nearbyActors.push_back(b);
        }
    }

    return  nearbyActors;
}

bool City::isGameOver() const
{
    return gameIsOver_;
}

void City::setPlayers(int players)
{
    amountOfPlayers_ = players;
}

void City::exitGame()
{
    exit(0);
}

void City::addPlayer()
{
    // All players' default location is the origin.

    mainW_->addPlayer(0,0,0);
}

void City::setDialog(Dialog* dialog)
{
    connect(dialog, SIGNAL(numberOfPlayers(int)), this, SLOT(setPlayers(int)));
    connect(dialog, SIGNAL(playerNames(QString, QString, QString, QString)),
            mainW_, SLOT(setPlayerNames(QString, QString, QString, QString)));
    connect(dialog, SIGNAL(exitFromDialog()), this, SLOT(exitGame()));

    dialog->exec();

}





