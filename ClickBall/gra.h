#ifndef GRA_H
#define GRA_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <akcja.h>
#include <ranking.h>
#include <zdrowie.h>

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
    Zdrowie* zdrowie;
public slots:
    void start();
    void rank();
    void back();
    //Rysowanie
    void drawTabela(int x, int y, int width, int height, QColor color, double opacity);
    void drawRanking();
};

#endif // GRA_H
