#ifndef ACTORITEM_HH
#define ACTORITEM_HH

#include "graphics/simpleactoritem.hh"
#include "beam.hh"
#include "player.hh"

#include <QPointF>
#include <QObject>
/* *
 * Contains player's operations.
 * Player is controlled by the user in the GUI (MainWindow).
 * */

class PlayerItem : public QObject, public CourseSide::SimpleActorItem
{
    Q_OBJECT

public:
    PlayerItem(int x, int y, int type);
    ~PlayerItem();
    
    
    // QGraphicsItem interface
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void setStartLoc();

    void setLocation(int x, int y);

    Beam* createBeam();

    void shoot();

private:
    QColor color_;
    Interface::Location* location_;
    QPointF target_;
    std::shared_ptr<Interface::ICity> gameArea_;
    int x_;
    int y_;
    int type_;
};

#endif // ACTORITEM_HH
