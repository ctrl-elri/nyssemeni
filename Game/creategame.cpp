#include "creategame.hh"
#include "city.hh"
#include "mainwindow.hh"

#include <algorithm>
#include <memory>


std::shared_ptr<Interface::ICity> Interface::createGame()
{

    QImage DEFAULT_MAP_PIC(":/offlinedata/offlinedata/kartta_pieni_500x500.png");
    QImage BIG_MAP_PIC(":/offlinedata/offlinedata/kartta_iso_1095x592.png");

    std::shared_ptr<City> city (new City);

    Dialog* dialog = new Dialog;
    city->setDialog(dialog);

    city->setMainWindow(new MainWindow(city));
    city->setBackground(DEFAULT_MAP_PIC, BIG_MAP_PIC);

    return city;
    
}
