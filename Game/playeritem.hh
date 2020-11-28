#ifndef ACTORITEM_HH
#define ACTORITEM_HH

#include "graphics/simpleactoritem.hh"
#include "beam.hh"
#include "interfaces/icity.hh"

#include <QDebug>
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

    Interface::Location getLocation();


    Beam* attackTarget(Interface::Location attackLoc);

private:

    Beam* createBeam(int xCoordinate, int yCoordinate);


    QColor color_;
    Interface::Location location_;
    QPointF target_;
    int x_;
    int y_;
    int type_;
    int locHeight_;
};

#endif // ACTORITEM_HH
