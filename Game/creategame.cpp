#include "creategame.hh"
#include "city.hh"
#include <algorithm>

#include <memory>

QImage DEFAULT_MAP_PIC(":/offlinedata/offlinedata/kartta_pieni_500x500.png");
QImage BIG_MAP_PIC(":/offlinedata/offlinedata/kartta_iso_1095x592.png");


std::shared_ptr<Interface::ICity> Interface::createGame()
{
    City* newCity = new City;
    newCity->setBackground(DEFAULT_MAP_PIC, BIG_MAP_PIC);

    std::shared_ptr<Interface::ICity> city = std::make_shared<Interface::ICity>(newCity);

    return city;
    
}
