#include "zdrowie.h"
#include "gra.h"
#include "dialog.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QtSql>
#include <QSqlDatabase>
#include <QFont>

extern Gra * gra;
Dialog* dialog;

Zdrowie::Zdrowie(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // Zerowanie rankingu
    zdrowie = 3;

    setPlainText(QString("Zdrowie: ") + QString::number(zdrowie));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));
}

void Zdrowie::utrata(){
    zdrowie--;
    setPlainText(QString("Zdrowie: ") + QString::number(zdrowie));
    // Koniec gry
    if (zdrowie == 0){
        gra->Spawntimer->disconnect();
        dialog = new Dialog();
        dialog->show();
        gra->drawTabela(0,0,1024,768,Qt::color0,1);
        //gra->displayMainMenu();
    }
    // Koniec gry
}

int Zdrowie::pokazzdrowie(){
    return zdrowie;
}
