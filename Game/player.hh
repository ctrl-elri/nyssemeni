#ifndef ACTORITEM_HH
#define ACTORITEM_HH
#include "graphics/simpleactoritem.hh"

/* *
 * Contains player's operations
 * */

class Player : public CourseSide::SimpleActorItem
{
public:
    Player(int x, int y, int type);
    ~Player();
    
    
    // QGraphicsItem interface
    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QColor color_;
    int x_;
    int y_;
    int type_;
};

#endif // ACTORITEM_HH
