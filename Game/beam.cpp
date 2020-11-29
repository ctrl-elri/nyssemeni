#include "beam.hh"



Beam::Beam(QPointF targetPos, QGraphicsItem *parent): QObject(), targetPos_(targetPos), QGraphicsPixmapItem(parent){

    //setPixmap(QPixmap(":/beam.jpg"));

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

}


QRectF Beam::boundingRect() const
{
    return QRectF(0,0,5,5);

}

void Beam::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QColor color(Qt::black);
    QRectF bounds = boundingRect();
    QBrush brush(color);
    painter->setBrush(brush);
    painter->drawEllipse(bounds);
}
