#ifndef BEAM_HH
#define BEAM_HH

#include <QObject>
#include <QTimer>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <qmath.h>

class Beam: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Beam(QGraphicsItem *parent = 0);

    // QGraphicsItem interface
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public slots:
    void move();


};

#endif // BEAM_HH
