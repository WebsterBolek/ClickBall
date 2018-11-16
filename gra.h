#ifndef GRA_H
#define GRA_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <akcja.h>
#include <ranking.h>

class Gra: public QGraphicsView{
    Q_OBJECT
public:
    // Konstruktor
    Gra(QWidget* parent=NULL);

    // Metoda wyswietlania menu
    void displayMainMenu();

    // Metody dla menu
    void displayRank();
    void displayAkcja();

    QGraphicsScene* scene;
    Akcja* akcja;
    Ranking* ranking;
public slots:
    void start();
    void rank();
    void back();
};

#endif // GRA_H
