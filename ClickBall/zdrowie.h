#ifndef ZDROWIE_H
#define ZDROWIE_H

#include <QGraphicsTextItem>

class Zdrowie: public QGraphicsTextItem{
public:
    Zdrowie(QGraphicsItem * parent=0);
    void utrata();
    int pokazzdrowie();

private:
    int zdrowie;
};

#endif // ZDROWIE_H
