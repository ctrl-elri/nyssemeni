#ifndef ACTORITEM_HH
#define ACTORITEM_HH

#include "graphics/simpleactoritem.hh"
#include "beam.hh"
#include "interfaces/icity.hh"

#include <QDebug>
#include <QPointF>
#include <QObject>

/**
 * @brief The PlayerItem class Pelaajahahmo, jota käyttäjä kontrolloi.
 */

class PlayerItem : public QObject, public CourseSide::SimpleActorItem
{
    Q_OBJECT

public:
    PlayerItem(int x, int y, int type);
    ~PlayerItem();
    

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

    /**
     * @brief setStartLoc Asettaa pelaajan aloitusaseman.
     */
    void setStartLoc();

    /**
     * @brief setLocation Asettaa pelaajan sijainnin pääikkunassa.
     * @param x sijainnin x-koordinaatti, muuttuu käyttäjän liikkuessa leveyssuunnassa.
     * @param y sijainnin y-koordinaatti, muuttuu käyttäjän liikkuesa pituussuunassa.
     */
    void setLocation(int x, int y);

    /**
     * @brief getLocation Antaa pelaajan sijainnin kutsuntahetkellä.
     * @return pelaajan sijainti.
     */
    Interface::Location getLocation();

    /**
     * @brief setBeam Luo Beam -olion ja asettaa sille suunnan ja sijainnin.
     * @param targetPosition Beamin kohteen sijainti: sijainti, johon Beam liikkuu.
     * @return Beam-olio.
     */
    Beam* setBeam(QPointF targetPosition);

    /**
     * @brief addPoints Lisää pelaajalle pisteitä.
     * @param pts lisättävät pisteet.
     */
    void addPoints(int pts);

    /**
     * @brief getPoints Antaa pelaajan pisteet kutsuntahetkellä.
     * @return pelaajan pisteet.
     */
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
