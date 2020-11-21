#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include "graphics/simplemainwindow.hh"
#include "graphics/simpleactoritem.hh"
#include "playeritem.hh"

#include <vector>
#include <map>

namespace Ui {
class MainWindow;
}

class MainWindow : public CourseSide::SimpleMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addActor(int locX, int locY, int type);

    void setPicture(QImage &img);

    void moveActorItem(std::shared_ptr<Interface::IActor> actorToBeMoved);

    void getActor(std::shared_ptr<Interface::IActor> newac);

    void addToMap();

    void removeActorItem(std::shared_ptr<Interface::IActor> actorToBeRemoved);

    void addPlayer(int locX, int locY, int type);


private:
    Ui::MainWindow *ui;
    QGraphicsScene *map;
    QTimer *timer;
    std::vector<PlayerItem*> players_;
    CourseSide::SimpleActorItem *lastItem_;
    std::shared_ptr<Interface::IActor> lastAc_;
    std::map<std::shared_ptr<Interface::IActor>, CourseSide::SimpleActorItem*> actors_;


    int width_ = 500; //pxls
    int height_ = 500;
    int tick_ = 500; //ms


};

#endif // MAINWINDOW_HH
