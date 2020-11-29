#include "playeritem.hh"


PlayerItem::PlayerItem(int x, int y, int type): QObject(), CourseSide::SimpleActorItem(x, y, type), x_(x), y_(y), type_(type), locHeight_(500)
{
    setPos(mapToParent(x_, y_ ));


}

PlayerItem::~PlayerItem()
{
    
}

void PlayerItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF bounds = CourseSide::SimpleActorItem::boundingRect();
    QColor color(Qt::red); //Adjust color
    QBrush brush(color_);
    painter->setBrush(brush);
    painter->drawEllipse(bounds);
}

void PlayerItem::setStartLoc()
{
    location_.setXY(x_, 500-y_);
}


void PlayerItem::setLocation(int x, int y)
{
    if (x == 0){
        location_.setXY(location_.giveX(), locHeight_-y+15);
        locHeight_ = locHeight_-y;
    } else if (y == 0){
        location_.setXY(x_+x+15, location_.giveY());
        x_ = x_ +x;
    }

    this->moveBy(x,y);
}

Interface::Location PlayerItem::getLocation()
{
    return location_;
}

Beam* PlayerItem::setBeam(QPointF targetPosition)
{
    Beam* beam = new Beam(targetPosition);

    QLineF ln(QPointF(x()+15, y()+15), targetPosition);
    int rotationAngle = -1 * ln.angle();

    beam->setPos(x()+15, y()+15);
    beam->setRotation(rotationAngle);

    return beam;
}
