#include "ranking.h"
#include "gra.h"
#include <QtSql>
#include <QFont>

Ranking::Ranking(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // Zerowanie rankingu
    ranking = 0;

    setPlainText(QString("Punkty: ") + QString::number(ranking));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));
}

void Ranking::punkt(){
    ranking++;
    setPlainText(QString("Punkty: ") + QString::number(ranking));
}

int Ranking::pokazranking(){
    return ranking;
}
