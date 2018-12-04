#include "ballukosna.h"
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

Ballukosna::Ballukosna(QGraphicsItem *parent): QObject(), QGraphicsEllipseItem(parent){
    //Losowe rozmieszczanie kuli
    int random_number = rand() % 768;
    setPos(random_number,0);

    // Rysowanie kuli
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
    setRect(0,0,80,80);

    // Czas
    QTimer * timer2 = new QTimer(this);
    if(pos().x() <= 512)
    {
        lot=0;
        connect(timer2,SIGNAL(timeout()),this,SLOT(move2()));
    }
    if(pos().x() > 512)
    {
        lot=1;
        connect(timer2,SIGNAL(timeout()),this,SLOT(move3()));
    }
    timer2->start(30);
}

void Ballukosna::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked2();
    gra->ranking->punkt();
    scene()->removeItem(this);
    delete this;
}

void Ballukosna::move2(){
    //Odbijanie
    if(lot == 1)
    {
        setPos(x()-10,y()+5);
        if(pos().x() <= 0)
        {
            lot=0;
        }
    }
    if(lot == 0)
    {
        setPos(x()+10,y()+5);
        if(pos().x() >= 944)
        {
            lot=1;
        }
    }
    //_________________________________________
    if(pos().y() > 788){
           // Spadek zycia
           gra->zdrowie->utrata();
           scene()->removeItem(this);
           delete this;
     }
}

void Ballukosna::move3(){
    //Odbijanie
    if(lot == 1)
    {
        setPos(x()-10,y()+5);
        if(pos().x() <= 0)
        {
            lot=0;
        }
    }
    if(lot == 0)
    {
        setPos(x()+10,y()+5);
        if(pos().x() >= 944)
        {
            lot=1;
        }
    }
    //_________________________________________
    if (pos().y() > 788){
           // Spadek zycia
           gra->zdrowie->utrata();
           scene()->removeItem(this);
           delete this;
     }
}

