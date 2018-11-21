#include "ball.h"
#include "gra.h"
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QRandomGenerator>

Ball::Ball(QGraphicsItem *parent): QGraphicsEllipseItem(parent){

    //quint32 v = QRandomGenerator::bounded(1000, 2000);
    quint32 value = QRandomGenerator::global()->generate();
    //setRect(randomx,0,100,50);
}



