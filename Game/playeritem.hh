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
    

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

    void setStartLoc();

    void setLocation(int x, int y);

    Interface::Location getLocation();

    Beam* setBeam(QPointF targetPosition);

    void addPoints(int pts);

    int getPoints();

private:

    QColor color_;
    Interface::Location location_;
    int x_;
    int y_;
    int type_;
    int locHeight_ ;
    int points_;

};

#endif // ACTORITEM_HH
