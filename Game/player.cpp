#include "player.hh"



Player::Player(int x, int y, int type): CourseSide::SimpleActorItem(x, y, type), x_(x), y_(y), type_(type) 
{
    setPos(mapToParent(x_, y_ ));
}

Player::~Player()
{
    
}

//void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
//{
//    QRectF bounds = CourseSide::SimpleActorItem::boundingRect();

//    if (type_ == 1){
//        color_ = QColor(0,0,255,255);
//    } else if (type_ == 2){
//        color_= QColor(255,0,0,255);
//    } else if (type_ == 3){
//        color_ = QColor(0,0,0,0);
//    }

//    QBrush brush(color_);
//    painter->setBrush(brush);
//    painter->drawEllipse(bounds);
//}
