#include "mainwindow.hh"
#include "ui_mainwindow.h"

const int PADDING = 10;
const int XTRA_PADDING = 80;

MainWindow::MainWindow(QWidget *parent) :
    CourseSide::SimpleMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->setStyleSheet("background-color: black;");
    ui->graphicsView->setFixedSize(width_, height_);
    ui->centralwidget->setFixedSize(width_ + ui->startButton->width() + PADDING + 2 * XTRA_PADDING, height_ + PADDING);

    ui->startButton->move(width_ + PADDING + XTRA_PADDING , XTRA_PADDING);
//    QPalette pal = ui->startButton->palette();
//    pal.setColor(QPalette::Button, QColor(Qt::blue));
//    ui->startButton->setAutoFillBackground(true);
//    ui->startButton->setPalette(pal);
//    ui->startButton->setVisible(1);


    map = new QGraphicsScene(this);
    ui->graphicsView->setScene(map);
    map->setSceneRect(0,0,width_,height_);

    resize(minimumSizeHint());
    //ui->gameView->fitInView(0,0, MAPWIDTH, MAPHEIGHT, Qt::KeepAspectRatio);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, map, &QGraphicsScene::advance);
    timer->start(tick_);}

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
        newX = newLoc.giveX();
        newY = newLoc.giveY();

        for (auto a: actors_){
            if (a.first == actorToBeMoved){
              a.second->setPos(newX, newY);
              return;
            }
        }
    }
}

void MainWindow::getActor(std::shared_ptr<Interface::IActor> newac)
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
        actors_.erase(actorToBeRemoved);
    }
}


