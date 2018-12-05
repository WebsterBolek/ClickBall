#include "gra.h"
#include <QApplication>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>

Gra* gra;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Precz z pseudolosowoscia
    qsrand(QDateTime::currentMSecsSinceEpoch() / 1000);
    qrand();

    gra = new Gra();
    gra->show();
    // Przejscie do menu gry
    gra->displayMainMenu();

    return a.exec();
}
