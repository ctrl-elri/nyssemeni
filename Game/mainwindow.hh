#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QCommonStyle>
#include <QTime>

#include "graphics/simplemainwindow.hh"
#include "graphics/simpleactoritem.hh"
#include "playeritem.hh"
#include "dialog.h"
#include "beam.hh"
#include "gameengine.hh"
#include "nysseitem.hh"
#include "gamestatistics.h"


#include <vector>
#include <map>
#include <algorithm>

const int NYSSE = 1000;

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
     * @brief Asettaa taustakuvan
     * @param img taustakuva, saadaan Citystä.
     */
    void setPicture(QImage &img);

    /**
     * @brief moveActorItem liikuttaa actorItemeitä peli-ikkunassa.
     * @param actorToBeMoved actor, jota vastaavaa actorItemiä liikutetaan.
     */
    void moveActorItem(std::shared_ptr<Interface::IActor> actorToBeMoved);

    /**
     * @brief setActor Asettaa attribuutin lastAc_ arvoksi viimeisimmän lisätyn actorin.
     * @param newac viimeisin lisätty actor, saadaan Citystä.
     */
    void setActor(std::shared_ptr<Interface::IActor> newac);

    /**
     * @brief addToMap Lisää parin actors_-mappiin, pari arvot ovat
     * key; lastAc_, ja value; *lastItem_.
     */
    void addToMap();

    /**
     * @brief removeActorItem Poistaa alkion actors_-mapista.
     * @param actorToBeRemoved elementin key-arvo, saadaan Citystä.
     */
    void removeActorItem(std::shared_ptr<Interface::IActor> actorToBeRemoved);

    /**
     * @brief addPlayer Lisää playerItemin peli-ikkunaan ja players_-vektoriin.
     * @param locX Aloitusaseman x-koordinaatti.
     * @param locY Aloitusaseman y-koordinaatti.
     * @param type itemin tyyppi.
     */
    void addPlayer(int locX, int locY, int type);

    /**
     * @brief checkPlayerMovement tarkistaa, että pelaaja liikkuu peli-ikkunan sisällä.
     */
    void checkPlayerMovement();


    void setStartingPlayer();

    void setScoreTable();

    void updateScoreTable();

    /**
     * @brief shootTarget Suorittaa ampumisen seuraukset.
     */
    void shootTarget();

signals:
    void exitFromMainwindow();

public slots:
    void setPlayerNames(QString name1, QString name2, QString name3, QString name4);


private slots:

    void on_moveRightBtn_clicked();

    void on_moveLeftBtn_clicked();

    void on_moveDownBtn_clicked();

    void on_moveUpBtn_clicked();

    void on_shootButton_clicked();

    void on_newgameButton_clicked();

    void on_exitButton_clicked();

private:

    /**
     * @brief isAnyActorNear Tarkistaa, onko playerItemin lähellä ammuttavia kohteita.
     * @param size vektorin, jossa ammuttavat kohteet on, koko.
     * @return true, jos vektori ei ole tyhjä, muulloin false.
     */
    bool isAnyActorNear(int size);

    Ui::MainWindow *ui;
    QGraphicsScene *map;
    QTimer *timer;
    QPalette hitLabelPal_;
    QTime time_;

    Beam* beam_;

    GameStatistics *statistics_;

    PlayerItem* currentPlayer_;
    std::vector<PlayerItem*> players_;
    std::vector<QString> playerNames_;

    CourseSide::SimpleActorItem *lastItem_;
    std::shared_ptr<Interface::IActor> lastAc_;

    std::vector<NysseItem*> nysses_;
    std::map<std::shared_ptr<Interface::IActor>, CourseSide::SimpleActorItem*> actors_;

    int turn_;
    int numberofplayers_;
    int width_ = 500; //pxls
    int height_ = 500;
    int tick_ = 500; //ms    


};

#endif // MAINWINDOW_HH
