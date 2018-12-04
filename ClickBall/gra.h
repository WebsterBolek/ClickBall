#ifndef GRA_H
#define GRA_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <ranking.h>
#include <zdrowie.h>
#include <ball.h>
#include <ballukosna.h>

class Gra: public QGraphicsView{
    Q_OBJECT
public:
    // Konstruktor
    Gra(QWidget* parent=NULL);

    //Zmienne
    int kulek;

    // Metoda wyswietlania menu
    void displayMainMenu();

    // Metody dla menu
    void displayRank();
    void gramy();

    QGraphicsScene* scene;
    Ranking* ranking;
    Zdrowie* zdrowie;
    Ball* ball;
    Ballukosna* ballukosna;
    QTimer* Spawntimer;

public slots:
    //Akcje menu
    void start();
    void rank();
    void back();
    //Rysowanie tabeli
    void drawTabela(int x, int y, int width, int height, QColor color, double opacity);
    void drawRanking();
    //Kule
    void spawn();
};

#endif // GRA_H
