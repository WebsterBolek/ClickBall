#ifndef BALL_H
#define BALL_H

#include <QGraphicsObject>

class Ball:public QObject, public QGraphicsEllipseItem{
    Q_OBJECT
public:
    Ball(QGraphicsItem * parent=0);
};

#endif // BALL_H
