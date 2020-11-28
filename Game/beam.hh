#ifndef BEAM_HH
#define BEAM_HH

#include <QObject>
#include <QTimer>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <qmath.h>

#include "core/location.hh"

class Beam: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Beam(qreal, qreal, QGraphicsItem *parent = 0);
    ~Beam();

    // QGraphicsItem interface
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public slots:
    void move();
private:
    int x_;
    int y_;
    QTimer *moveTimer_;

};

#endif // BEAM_HH
