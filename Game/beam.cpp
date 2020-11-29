#include "beam.hh"



Beam::Beam(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    setPixmap(QPixmap(":/beam.png").scaled(10,10));


    moveTimer_ = new QTimer(this);
    connect(moveTimer_,SIGNAL(timeout()),this,SLOT(move()));
    moveTimer_->start(50);
}

Beam::~Beam()
{

}

void Beam::move()
{


    int STEP_SIZE = 5;
    double theta = rotation();

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy);

    ++timesMoved_;

    if (timesMoved_ == 3){
        moveTimer_->stop();
        delete this;
    }

}

int Beam::getTimesMove()
{
    return timesMoved_;
}
