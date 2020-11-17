#include "city.hh"

City::City():Interface::ICity()
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

void City::startGame()
{

}





