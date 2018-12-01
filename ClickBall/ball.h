#ifndef BALL_H
#define BALL_H

#include <QGraphicsEllipseItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>
#include <QGraphicsItem>

class Ball: public QObject,public QGraphicsEllipseItem{
    Q_OBJECT
public:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    Ball(QGraphicsItem * parent=0);
    QTimer* timer;
public slots:
    void move();
signals:
    void clicked();
};

#endif // BALL_H
