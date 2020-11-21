#ifndef ACTORITEM_HH
#define ACTORITEM_HH
#include "graphics/simpleactoritem.hh"

/* *
 * Contains player's operations.
 * Player is controlled by the user in the GUI (MainWindow).
 * */

class Player : public CourseSide::SimpleActorItem
{
public:
    Player(int x, int y, int type);
    ~Player();
    
    
    // QGraphicsItem interface
    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void move(int x, int y);
    void shoot();

private:
    QColor color_;
    int x_;
    int y_;
    int type_;
};

#endif // ACTORITEM_HH
