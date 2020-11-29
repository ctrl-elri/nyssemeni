#ifndef NYSSEITEM_HH
#define NYSSEITEM_HH

#include "graphics/simpleactoritem.hh"

class NysseItem: public QObject, public CourseSide::SimpleActorItem
{
    Q_OBJECT
public:
    NysseItem(int, int, int);
    ~NysseItem();

public:

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void changeColor();

private:
    int x_;
    int y_;
    int type_;
    QBrush brush_;
    bool colorChanged_;
};

#endif // NYSSEITEM_HH
