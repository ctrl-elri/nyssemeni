#include "beam.hh"



Beam::Beam(qreal xCoordinate, qreal yCoordinate, QGraphicsItem *parent): QObject(), x_(xCoordinate), y_(yCoordinate), QGraphicsPixmapItem(parent){

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
    //Koordinaatit joihin beam liikkuu. Liikkumisen jälkeen tuhoutuu.

    int STEP_SIZE = 15;
    double theta = rotation();

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy);

    if (x() == x_){
        moveTimer_->stop();
        return;
    }

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
