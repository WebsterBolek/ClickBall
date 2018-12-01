#include "ball.h"
#include "gra.h"
#include "ranking.h"
#include <QGraphicsScene>
#include <QBrush>
#include <QList>
#include <stdlib.h>
#include <QTimer>
#include <QDebug>
#include <QGraphicsEllipseItem>
#include <QGraphicsSceneMouseEvent>

extern Gra * gra;

Ball::Ball(QGraphicsItem *parent): QObject(), QGraphicsEllipseItem(parent){
    //Losowe rozmieszczanie kuli
    int random_number = rand() % 768;
    setPos(random_number,0);

    // Rysowanie kuli
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::green);
    setBrush(brush);
    setRect(0,0,100,100);

    // Czas
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(20);
}

void Ball::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
    gra->ranking->punkt();
    scene()->removeItem(this);
    delete this;
}

void Ball::move(){
    // Spadanie
    setPos(x(),y()+5);
    if (pos().y() > 768){
           // Spadek zycia
           gra->zdrowie->utrata();
           scene()->removeItem(this);
           delete this;
     }
}
