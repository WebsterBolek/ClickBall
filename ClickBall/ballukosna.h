#ifndef BALLUKOSNA_H
#define BALLUKOSNA_H

#include <QGraphicsEllipseItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>
#include <QGraphicsItem>

class Ballukosna: public QObject,public QGraphicsEllipseItem{
    Q_OBJECT
public:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    Ballukosna(QGraphicsItem * parent=0);
    QTimer* timer2;
    //Zmienna kierunku lotu
    int lot;
public slots:
    void move2();
    void move3();
signals:
    void clicked2();
};

#endif // BALLUKOSNA_H
