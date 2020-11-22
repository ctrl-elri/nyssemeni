#include "playeritem.hh"



PlayerItem::PlayerItem(int x, int y, int type): QObject(), CourseSide::SimpleActorItem(x, y, type), x_(x), y_(y), type_(type)
{
    setPos(mapToParent(x_, y_ ));
}

PlayerItem::~PlayerItem()
{
    
}

void PlayerItem::shoot()
{
    // Create class for fire, setPos as the middle of player item
}


void PlayerItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF bounds = CourseSide::SimpleActorItem::boundingRect();
    QColor color(Qt::red); //Adjust color
    QBrush brush(color_);
    painter->setBrush(brush);
    painter->drawEllipse(bounds);
}
