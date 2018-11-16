#include "Wybor.h"
#include <QGraphicsTextItem>
#include <QBrush>

Wybor::Wybor(QString name, QGraphicsItem *parent): QGraphicsEllipseItem(parent){
    // Guzik
    setRect(0,0,100,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::green);
    setBrush(brush);

    // Tekst na guzikach
    text = new QGraphicsTextItem(name,this);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

    // Aktywacja podswietlenia
    setAcceptHoverEvents(true);
}

void Wybor::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
}

void Wybor::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    // Kolor podswietlenia po najechaniu
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
}

void Wybor::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    // Kolor zmiany po wyjsciu
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::green);
    setBrush(brush);
}
