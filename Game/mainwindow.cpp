#include "mainwindow.hh"
#include "ui_mainwindow.h"

#include <QtDebug>

const int PADDING = 10;
const int XTRA_PADDING = 80;

MainWindow::MainWindow(std::shared_ptr<Interface::ICity> gameArea, QWidget *parent) :
    CourseSide::SimpleMainWindow(parent),
    ui(new Ui::MainWindow)
{
    gameArea_ = gameArea;
    ui->setupUi(this);
    //this->setStyleSheet("background-color: black;");
    ui->graphicsView->setFixedSize(width_, height_);
    ui->centralwidget->setFixedSize(width_ + ui->moveUpBtn->width() + PADDING + 2 * XTRA_PADDING, height_ + PADDING);

    ui->moveUpBtn->move(width_ + PADDING + XTRA_PADDING , XTRA_PADDING);
    ui->moveRightBtn->move(width_ + PADDING + XTRA_PADDING + ui->moveUpBtn->width()/2, XTRA_PADDING + ui->moveUpBtn->height());
    ui->moveLeftBtn->move(width_ + PADDING + XTRA_PADDING/2, XTRA_PADDING + ui->moveUpBtn->height());
    ui->moveDownBtn->move(width_ + PADDING + XTRA_PADDING, XTRA_PADDING + 2* ui->moveUpBtn->height());
    ui->hitLabel->move(width_ + PADDING + XTRA_PADDING, 350);
    ui->shootButton->move(width_ + PADDING + XTRA_PADDING, 400);
    ui->newgameButton->move(width_ + PADDING + XTRA_PADDING, 450);

    QCommonStyle style;
    ui->moveRightBtn->setIcon(style.standardIcon(QStyle::SP_ArrowForward));
    ui->moveLeftBtn->setIcon(style.standardIcon(QStyle::SP_ArrowBack));
    ui->moveUpBtn->setIcon(style.standardIcon(QStyle::SP_ArrowUp));
    ui->moveDownBtn->setIcon(style.standardIcon(QStyle::SP_ArrowDown));


    map = new QGraphicsScene(this);
    ui->graphicsView->setScene(map);
    map->setSceneRect(0,0,width_,height_);

    resize(minimumSizeHint());
    //ui->gameView->fitInView(0,0, MAPWIDTH, MAPHEIGHT, Qt::KeepAspectRatio);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, map, &QGraphicsScene::advance);
    timer->start(tick_);

    QTimer::singleShot(300, ui->hitLabel, &QLabel::hide);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::addActor(int locX, int locY, int type)
{
    CourseSide::SimpleActorItem* nActor = new CourseSide::SimpleActorItem(locX, locY, type);
    map->addItem(nActor);
    lastItem_ = nActor;

}

void MainWindow::setPicture(QImage &img)
{
    map->setBackgroundBrush(img);
}

void MainWindow::moveActorItem(std::shared_ptr<Interface::IActor> actorToBeMoved)
{
    int newX = 0;
    int newY = 0;

    if (actors_.find(actorToBeMoved) == actors_.end()){
        return;
    } else {
        Interface::Location newLoc = actorToBeMoved->giveLocation();
        newX = newLoc.giveX()-5;
        newY = 500-newLoc.giveY()-5;

        for (auto a: actors_){
            if (a.first == actorToBeMoved){
              a.second->setPos(newX, newY);
            }
        }
    }
}

void MainWindow::setActor(std::shared_ptr<Interface::IActor> newac)
{
    lastAc_ = newac;
}

void MainWindow::addToMap()
{
    actors_.insert({lastAc_, lastItem_});
}

void MainWindow::removeActorItem(std::shared_ptr<Interface::IActor> actorToBeRemoved)
{
    if (actors_.find(actorToBeRemoved) == actors_.end()){
        return;
    } else {
        map->removeItem(actors_.find(actorToBeRemoved)->second);
        actors_.erase(actorToBeRemoved);
    }
}

void MainWindow::addPlayer(int locX, int locY, int type)
{
    PlayerItem* player = new PlayerItem(locX, locY, type);
    player->setStartLoc();
    map->addItem(player);

    players_.push_back(player);
}

void MainWindow::checkPlayerMovement()
{
    for (auto p: players_){

        if (p->x() > 500-15){
            ui->moveRightBtn->setDisabled(true);
        } else if (p->x() <= 500+15){
            ui->moveRightBtn->setDisabled(false);
        }

        if (p->x() <= 0){
            ui->moveLeftBtn->setDisabled(true);
        } else if (p->x() > 0){
            ui->moveLeftBtn->setDisabled(false);
        }

        if (p->y() <= 0){
            ui->moveUpBtn->setDisabled(true);
        } else if (p->y() > 0) {
            ui->moveUpBtn->setDisabled(false);
        }

        if (p->y() > 500-15){
            ui->moveDownBtn->setDisabled(true);
        } else if (p->y() <= 500+15){
            ui->moveDownBtn->setDisabled(false);
        }
    }
}

void MainWindow::removeNearbyActors(std::vector<std::shared_ptr<Interface::IActor> > nearbyActors)
{
    if (nearbyActors.size() == 0){
        return;
    } else {
        // Poistaa hyökkäyksen kohteena olevat actorItemit.
        for (auto nA: nearbyActors){
            if (actors_.find(nA) == actors_.end()){
                continue;
            } else {
                if (beam_->collidesWithItem(actors_.find(nA)->second)){
                    gameArea_->removeActor(nA);
                    ui->hitLabel->setVisible(true);
                    ui->hitLabel->adjustSize();
                    ui->hitLabel->setText("Target hit!");
                    delete beam_;
                }
            }
        }
    }

}

void MainWindow::openDialog()
{
    Dialog *dialog = new Dialog;
    connect(dialog, SIGNAL(GameTime(QTime)), this, SLOT(setTime(QTime)));
    connect(dialog, SIGNAL(NumberOfPlayers(int)), this, SLOT(setNumberOfPlayers(int)));
    connect(dialog, SIGNAL(Exit()), this, SLOT(exitGame()));
    dialog->exec();
}

QTime MainWindow::addNewTime()
{
    return time_;
}

int MainWindow::addNewPlayers()
{
    return numberofplayers_;
}



void MainWindow::on_moveRightBtn_clicked()
{
    for (auto p: players_){
        p->setLocation(15,0);
    }
    checkPlayerMovement();

}

void MainWindow::on_moveLeftBtn_clicked()
{
    for (auto p: players_){
        p->setLocation(-15,0);
    }
    checkPlayerMovement();

}



void MainWindow::on_moveDownBtn_clicked()
{
    for (auto p: players_){
        p->setLocation(0,15);
    }
    checkPlayerMovement();

}

void MainWindow::on_moveUpBtn_clicked()
{
    for (auto p: players_){
        p->setLocation(0,-15);
    }
    checkPlayerMovement();

}

void MainWindow::setTime(QTime time)
{
    time_ = time;
    qDebug("Aika asetettu");

}

void MainWindow::setNumberOfPlayers(int number)
{
    numberofplayers_ = number;
}

void MainWindow::on_shootButton_clicked()
{

    Interface::Location playersLoc = players_.at(0)->getLocation();
    std::vector<std::shared_ptr<Interface::IActor> > actorsInRange = gameArea_->getNearbyActors(playersLoc);

    if(isAnyActorNear(actorsInRange.size())){

        for (auto nA: actorsInRange){
            if (actors_.find(nA) == actors_.end()){
                continue;
            } else {
                QPointF targetLoc = actors_.find(nA)->second->pos();
                beam_ = players_.at(0)->setBeam(targetLoc);
                map->addItem( beam_);
            }
        }

        removeNearbyActors(actorsInRange);

    } else {
        return;
    }

}

void MainWindow::on_newgameButton_clicked()
{
    this->close();

    // Starting new game
    gameEngine* engine = new gameEngine;
    engine->initGame();

}

void MainWindow::exitGame()
{
    // ??

}

bool MainWindow::isAnyActorNear(int size)
{
    if (size == 0){
        ui->hitLabel->setVisible(true);
        ui->hitLabel->adjustSize();
        ui->hitLabel->setText("Target isn't near enough!");
        return false;
    }

    return true;
}

