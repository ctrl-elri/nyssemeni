#ifndef CITY_HH
#define CITY_HH

#include "interfaces/icity.hh"
#include "mainwindow.hh"
#include "interfaces/istop.hh"
#include "actors/stop.hh"
#include "actors/nysse.hh"
#include "actors/passenger.hh"

#include <QTime>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <QObject>

const int NYSSE_TYPE = 1000;
const int PASSENGER_TYPE = 400;
const int STOP_TYPE = 600;

class City : public Interface::ICity
{
public:
    City();
    ~City();

    void setMainWindow(MainWindow* window);
    /**
     * @brief addPlayer adds the player actor
     * Player amount from Dialog? Player is added when pressed startButton?
     */
    void addPlayer();

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


public slots:
    void shoot();

private:
    QTime time_;
    //Dialog *dialog_;
    MainWindow *mainW_;
    bool gameIsOver_ = true;
    std::vector<std::shared_ptr<Interface::IActor> > actorsInGame_;
    std::vector<std::shared_ptr<Interface::IActor> > actorsRemoved_;
    std::vector< std::shared_ptr<Interface::IStop> > stops_;

};




#endif // CITY_HH
