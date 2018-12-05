#ifndef RANKING_H
#define RANKING_H

#include <QGraphicsTextItem>
#include "dialog.h"

class Ranking: public QGraphicsTextItem{
public:
    Ranking(QGraphicsItem * parent=0);
    void punkt();
    int pokazranking();

private:
    int ranking;
};

#endif // RANKING_H
