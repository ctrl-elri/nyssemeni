#include "creategame.hh"
#include "city.hh"
#include <algorithm>
#include <iostream>
#include <string>

QImage DEFAULT_MAP_PIC(":/offlinedata/offlinedata/kartta_pieni_500x500.png");
QImage BIG_MAP_PIC(":/offlinedata/offlinedata/kartta_iso_1095x592.png");


std::shared_ptr<Interface::ICity> Interface::createGame()
{
    //::ICity *newCity = std::getObject(true);
    Interface::ICity *city = static_cast<City*>();
    city->setBackground(DEFAULT_MAP_PIC, BIG_MAP_PIC);

    std::shared_ptr<Interface::ICity> c(city);

    //return city;
    
}
