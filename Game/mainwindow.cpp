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
    ui->shootButton->move(width_ + PADDING + XTRA_PADDING, 400);
    ui->newgameButton->move(width_ + PADDING + 65, 430);
    ui->exitButton->move(width_ + PADDING + 75, 470);
    ui->currentPlayer->move(540,50);

    ui->scoreLabel->move(width_ + PADDING + XTRA_PADDING + 20, 200);
    ui->player1Label->move(width_ + PADDING + 60, 230);
    ui->player2Label->move(width_ + PADDING + 60, 260);
    ui->player3Label->move(width_ + PADDING + 60, 290);
    ui->player4Label->move(width_ + PADDING + 60, 320);

    ui->player1Label->setText("");
    ui->player2Label->setText("");
    ui->player3Label->setText("");
    ui->player4Label->setText("");

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

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::addActor(int locX, int locY, int type)
{
    if (type == NYSSE){
        NysseItem* nActor = new NysseItem(locX, locY, type);
        map->addItem(nActor);
        nysses_.push_back(nActor);
        lastItem_ = nActor;
    } else {
        CourseSide::SimpleActorItem* nActor = new CourseSide::SimpleActorItem(locX, locY, type);
        map->addItem(nActor);
        lastItem_ = nActor;
    }

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
     if (currentPlayer_->x() > 500-15){
        ui->moveRightBtn->setDisabled(true);
     } else if (currentPlayer_->x() <= 500+15){
            ui->moveRightBtn->setDisabled(false);
        }

     if (currentPlayer_->x() <= 0){
        ui->moveLeftBtn->setDisabled(true);
     } else if (currentPlayer_->x() > 0){
            ui->moveLeftBtn->setDisabled(false);
        }

     if (currentPlayer_->y() <= 0){
        ui->moveUpBtn->setDisabled(true);
     } else if (currentPlayer_->y() > 0) {
            ui->moveUpBtn->setDisabled(false);
        }

     if (currentPlayer_->y() > 500-15){
        ui->moveDownBtn->setDisabled(true);
     } else if (currentPlayer_->y() <= 500+15){
            ui->moveDownBtn->setDisabled(false);
        }

}


void MainWindow::setStartingPlayer()
{
    turn_ = 0;
    currentPlayer_ = players_.at(turn_);
    ui->currentPlayer->setText(("Player's turn: ") + playerNames_.at(turn_));

}

void MainWindow::updateScoreTable()
{
    int players = players_.size();
    qDebug() << players << "Pelaajien lkm";

    if (players == 1) {
        ui->player1Label->setText(playerNames_.at(0) + ": "
                                  + QString::number(statistics_->checkPlayerPoints(0)) + " points");
    }
    else if (players == 2) {
        ui->player1Label->setText(playerNames_.at(0) + ": "
                                  + QString::number(statistics_->checkPlayerPoints(0)) + " points");
        ui->player2Label->setText(playerNames_.at(1) + ": "
                                  + QString::number(statistics_->checkPlayerPoints(1)) + " points");
    }
    else if (players == 3) {
        ui->player1Label->setText(playerNames_.at(0) + ": "
                                  + QString::number(statistics_->checkPlayerPoints(0)) + " points");
        ui->player2Label->setText(playerNames_.at(1) + ": "
                                  + QString::number(statistics_->checkPlayerPoints(1)) + " points");
        ui->player2Label->setText(playerNames_.at(2) + ": "
                                  + QString::number(statistics_->checkPlayerPoints(2)) + " points");
    }
    else if (players == 4) {
        ui->player1Label->setText(playerNames_.at(0) + ": "
                                  + QString::number(statistics_->checkPlayerPoints(0)) + " points");
        ui->player2Label->setText(playerNames_.at(1) + ": "
                                  + QString::number(statistics_->checkPlayerPoints(1)) + " points");
        ui->player3Label->setText(playerNames_.at(2) + ": "
                                  + QString::number(statistics_->checkPlayerPoints(2)) + " points");
        ui->player4Label->setText(playerNames_.at(3) + ": "
                                  + QString::number(statistics_->checkPlayerPoints(3)) + " points");

    }

}

void MainWindow::setScoreTable()
{
    statistics_ = new GameStatistics;
    statistics_->initGameStatics(players_.size());
    updateScoreTable();
}

void MainWindow::setPlayerNames(QString name1, QString name2, QString name3, QString name4)
{
    playerNames_.push_back(name1);
    playerNames_.push_back(name2);
    playerNames_.push_back(name3);
    playerNames_.push_back(name4);

}

void MainWindow::on_moveRightBtn_clicked()
{
    currentPlayer_->setLocation(15,0);
    checkPlayerMovement();

}

void MainWindow::on_moveLeftBtn_clicked()
{
    currentPlayer_->setLocation(-15,0);
    checkPlayerMovement();

}


void MainWindow::on_moveDownBtn_clicked()
{
    currentPlayer_->setLocation(0,15);
    checkPlayerMovement();

}

void MainWindow::on_moveUpBtn_clicked()
{
    currentPlayer_->setLocation(0,-15);
    checkPlayerMovement();

}


void MainWindow::on_shootButton_clicked()
{
    //beam_:n toiminnallisuutta muokataan vielä.

    beam_= new Beam;
    beam_->setPos(players_.at(turn_)->pos().x()+15, players_.at(turn_)->pos().y()+15);
    beam_->setRotation(-2 * 500);
    map->addItem(beam_);


    Interface::Location playersLoc = players_.at(turn_)->getLocation();
    std::vector<std::shared_ptr<Interface::IActor> > actorsInRange = gameArea_->getNearbyActors(playersLoc);

    if(isAnyActorNear(actorsInRange.size())){

        for (auto nA: actorsInRange){

            if (actors_.find(nA) == actors_.end()){
                continue;

            } else {

                QPointF targetLoc = actors_.at(nA)->pos();
                beam_ = players_.at(turn_)->setBeam(targetLoc);
                map->addItem(beam_);

                NysseItem* moveNysse = dynamic_cast<NysseItem*>(actors_.at(nA));
                moveNysse->changeColor();
            }

        }

    } else {
        return;
    }

    // Pelaajan vuoro vaihtuu aina kun pelaaja on ampunut.
    // Mainwindowin turn_ määrittää, kenen vuoro on pelata.

    // Määritetään seuraava pelaaja ja vaihdetaan vuoro

    if ( turn_ + 1 == players_.size() ) {
        turn_ = 0;
    }
    else {
        turn_ = turn_ + 1;
    }

    ui->currentPlayer->setText(("Player's turn: ") + playerNames_.at(turn_));
    currentPlayer_ = players_.at(turn_);

}

void MainWindow::on_newgameButton_clicked()
{
    this->close();

    // Starting new game
    gameEngine* engine = new gameEngine;
    engine->initGame();

}



bool MainWindow::isAnyActorNear(int size)
{
    if (size == 0){
//        ui->hitLabel->setVisible(true);
//        ui->hitLabel->adjustSize();
//        ui->hitLabel->setText("Target isn't near enough!");
        return false;
    }

    return true;
}

void MainWindow::on_exitButton_clicked()
{
    emit exitFromMainwindow();
}
