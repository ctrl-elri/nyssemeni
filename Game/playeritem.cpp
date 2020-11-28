#include "playeritem.hh"


PlayerItem::PlayerItem(int x, int y, int type): QObject(), CourseSide::SimpleActorItem(x, y, type), x_(x), y_(y), type_(type), locHeight_(500)
{
    setPos(mapToParent(x_, y_ ));


}

PlayerItem::~PlayerItem()
{
    
}

Beam* PlayerItem::createBeam(int xCoordinate, int yCoordinate)
{
    Beam* beam = new Beam(xCoordinate, yCoordinate);
    beam->setPos(x()+15, y()+15);

    return beam;

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
        location_.setXY(location_.giveX(), locHeight_-y);
        locHeight_ = locHeight_-y;
    } else if (y == 0){
        location_.setXY(x_+x, location_.giveY());
        x_ = x_ +x;
    }

    this->moveBy(x,y);
}

Interface::Location PlayerItem::getLocation()
{
    return location_;
}

Beam* PlayerItem::attackTarget(Interface::Location attackLoc)
{
    int x = attackLoc.giveX();
    int y = attackLoc.giveY();

    return createBeam(x,y);
}
