#ifndef ACTORITEM_HH
#define ACTORITEM_HH
#include "graphics/simpleactoritem.hh"


class ActorItem : public CourseSide::SimpleActorItem
{
public:
    ActorItem(int x, int y, int type);
    ~ActorItem();
    
    
    // QGraphicsItem interface
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QColor color_;
    int x_;
    int y_;
    int type_;
};

#endif // ACTORITEM_HH
