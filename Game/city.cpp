#include "city.hh"

City::City():Interface::ICity()
{
    
}

void City::setBackground(QImage &basicbackground, QImage &bigbackground)
{
   CourseSide::SimpleMainWindow* ui = new CourseSide::SimpleMainWindow;
   ui->setPicture(basicbackground);
}


