#include "gameengine.hh"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(offlinedata);
    gameEngine* logic = new gameEngine;

    return a.exec();
}
