#include "playeritem.hh"



PlayerItem::PlayerItem(int x, int y, int type): QObject(), CourseSide::SimpleActorItem(x, y, type), x_(x), y_(y), type_(type)
{
    setPos(mapToParent(x_, y_ ));
}

PlayerItem::~PlayerItem()
{
    
}

Beam* PlayerItem::shoot()
{
    Beam* beam = new Beam;
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
