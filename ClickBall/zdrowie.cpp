#include "zdrowie.h"
#include <QtSql>
#include <QFont>

Zdrowie::Zdrowie(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // Zerowanie rankingu
    zdrowie = 0;


    setPlainText(QString("Zdrowie: ") + QString::number(zdrowie));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));
}

void Zdrowie::utrata(){
    zdrowie++;
    setPlainText(QString("Zdrowie: ") + QString::number(zdrowie));
}

int Zdrowie::pokazzdrowie(){
    return zdrowie;
}
