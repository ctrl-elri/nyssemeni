#include "creategame.hh"
#include "city.hh"

QImage DEFAULT_MAP_PIC(":/offlinedata/offlinedata/kartta_pieni_500x500.png");
QImage BIG_MAP_PIC(":/offlinedata/offlinedata/kartta_iso_1095x592.png");


std::shared_ptr<Interface::ICity> Interface::createGame()
{
    Interface::ICity* iCity = new City;
    iCity->setBackground(DEFAULT_MAP_PIC, BIG_MAP_PIC);
    return 0;
    
}
