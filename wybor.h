#ifndef WYBOR_H
#define WYBOR_H

//#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsSceneMouseEvent>

class Wybor:public QObject, public QGraphicsEllipseItem{
    Q_OBJECT
public:
    // Konstruktor
    Wybor(QString name, QGraphicsItem* parent=NULL);

    // Dzialanie na myszy
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
signals:
    void clicked();
private:
    QGraphicsTextItem* text;
};

#endif // WYBOR_H
