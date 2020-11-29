#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QCommonStyle>
#include <QTime>

#include "graphics/simplemainwindow.hh"
#include "graphics/simpleactoritem.hh"
#include "playeritem.hh"
#include "dialog.h"
#include "gameengine.hh"


#include <vector>
#include <map>

namespace Ui {
class MainWindow;
}

class MainWindow : public CourseSide::SimpleMainWindow
{
    std::shared_ptr<Interface::ICity> gameArea_;

    Q_OBJECT

public:
    explicit MainWindow(std::shared_ptr<Interface::ICity>, QWidget *parent = 0);
    ~MainWindow();

    void addActor(int locX, int locY, int type);

    /**
     * @brief setPicture sets the background picture.
     * @param img background picture, from City.
     */
    void setPicture(QImage &img);

    /**
     * @brief moveActorItem moves actor's actoritem in window.
     * @param actorToBeMoved actor whose actoritem is to be moved, from City.
     */
    void moveActorItem(std::shared_ptr<Interface::IActor> actorToBeMoved);

    /**
     * @brief setActor sets latest added actor as lastAc_.
     * @param newac latest added actor, from City.
     */
    void setActor(std::shared_ptr<Interface::IActor> newac);

    /**
     * @brief addToMap adds a pair to map, actors_, the pair consisting of
     * key; lastAc_, and value; *lastItem_.
     */
    void addToMap();

    /**
     * @brief removeActorItem removes an element from map, actors_.
     * @param actorToBeRemoved key to the element which is to be removed, from City.
     */
    void removeActorItem(std::shared_ptr<Interface::IActor> actorToBeRemoved);

    /**
     * @brief addPlayer adds a playeritem to the window and to the vector players_.
     * @param locX starting position's x-coordinate.
     * @param locY starting position's y-coordinate.
     * @param type item's type.
     */
    void addPlayer(int locX, int locY, int type);

    /**
     * @brief checkPlayerMovement checks that the player moves within window.
     */
    void checkPlayerMovement();

    void removeNearbyActors(std::vector<std::shared_ptr<Interface::IActor> > nearbyActors);


private slots:

    void on_moveRightBtn_clicked();

    void on_moveLeftBtn_clicked();

    void on_moveDownBtn_clicked();

    void on_moveUpBtn_clicked();

    void on_shootButton_clicked();

    void on_newgameButton_clicked();


private:
    Ui::MainWindow *ui;
    QGraphicsScene *map;
    QTimer *timer;
    std::vector<PlayerItem*> players_;
    std::vector<Beam*> beams_;
    CourseSide::SimpleActorItem *lastItem_;
    std::shared_ptr<Interface::IActor> lastAc_;
    std::map<std::shared_ptr<Interface::IActor>, CourseSide::SimpleActorItem*> actors_;


    int width_ = 500; //pxls
    int height_ = 500;
    int tick_ = 500; //ms    


};

#endif // MAINWINDOW_HH
