#ifndef CITY_HH
#define CITY_HH

#include "interfaces/icity.hh"
#include "graphics/simplemainwindow.hh"
#include <QTime>

class City : public Interface::ICity
{
    
public:
    City();
    virtual ~City();
    // ICity interface
    void setBackground(QImage &basicbackground, QImage &bigbackground);
    void setClock(QTime clock);
    void addStop(std::shared_ptr<Interface::IStop> stop);
    void startGame();
    void addActor(std::shared_ptr<Interface::IActor> newactor);
    void removeActor(std::shared_ptr<Interface::IActor> actor);
    void actorRemoved(std::shared_ptr<Interface::IActor> actor);
    bool findActor(std::shared_ptr<Interface::IActor> actor) const;
    void actorMoved(std::shared_ptr<Interface::IActor> actor);
    std::vector<std::shared_ptr<Interface::IActor> > getNearbyActors(Interface::Location loc) const;
    bool isGameOver() const;

    QTime getTime();

private:
    QTime time_;
 
};


#endif // CITY_HH
