#ifndef BEAM_HH
#define BEAM_HH

#include <QObject>
#include <QTimer>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QPainter>
#include <qmath.h>
#include <QDebug>

#include "core/location.hh"

class Beam: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Beam(QGraphicsItem *parent = 0);
    ~Beam();

    int getTimesMove();

public slots:
    void move();
private:
    int x_;
    int y_;
    int timesMoved_ = 0;
    QTimer *moveTimer_;

};

#endif // BEAM_HH
