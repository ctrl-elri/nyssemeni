#ifndef ACTORITEM_HH
#define ACTORITEM_HH

#include "graphics/simpleactoritem.hh"
#include "core/location.hh"

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

    Interface::Location giveLocation();

public slots:
    void shoot();

private:
    QColor color_;
    Interface::Location* location_;
    QPointF target_;
    int x_;
    int y_;
    int type_;
};

#endif // ACTORITEM_HH
