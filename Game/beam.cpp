#include "beam.hh"



Beam::Beam(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent){

    setPixmap(QPixmap(":/beam.jpg"));

    QTimer *move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(50);
}

void Beam::move()
{
    int STEP_SIZE = 30;
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
