#include "gra.h"
#include "wybor.h"
#include "ranking.h"
#include "zdrowie.h"
#include <QGraphicsTextItem>
#include <QGraphicsObject>

Gra::Gra(QWidget *parent){
    // Ustawianie rozdzielczosci
    setFixedSize(1024,768);

    // Blokada przesuwania paskow
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Scena gry
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1024,768);
    setScene(scene);
}

// Menu -------------------------------------------------------------------
void Gra::displayMainMenu(){
    // Tytul
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("ClickBall"));
    QFont titleFont("times new roman",60);
    titleText->setFont(titleFont);

    // Ustawienie pozycji tytulu
    int axPos = this->width()/2 - titleText->boundingRect().width()/2;
    int ayPos = 150;
    titleText->setPos(axPos,ayPos);
    scene->addItem(titleText); //wstawienie

    // Wersja
    QGraphicsTextItem* titleText2 = new QGraphicsTextItem(QString("Wersja demonstracyjna. Bardzo wczesna alfa!!"));
    QFont titleFont2("Arial",14);
    titleText2->setFont(titleFont2);

    // Ustawienie pozycji wersji
    int bxPos = this->width()/2 - titleText->boundingRect().width()/2;
    int byPos = 660;
    titleText2->setPos(bxPos,byPos);
    scene->addItem(titleText2); //wstawienie

    // Przycisk Graj
    Wybor* grajWybor = new Wybor(QString("Graj"));
    int cxPos = this->width()/2 - grajWybor->boundingRect().width()/2;
    int cyPos = 275;
    grajWybor->setPos(cxPos,cyPos);
    connect(grajWybor,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(grajWybor);

    // Przycisk Ranking
    Wybor* rankWybor = new Wybor(QString("Ranking"));
    int dxPos = this->width()/2 - rankWybor->boundingRect().width()/2;
    int dyPos = 350;
    rankWybor->setPos(dxPos,dyPos);
    connect(rankWybor,SIGNAL(clicked()),this,SLOT(rank()));
    scene->addItem(rankWybor);

    // Przycisk Wyjdz
    Wybor* wyjWybor = new Wybor(QString("Wyjdz"));
    int exPos = this->width()/2 - wyjWybor->boundingRect().width()/2;
    int eyPos = 425;
    wyjWybor->setPos(exPos,eyPos);
    connect(wyjWybor,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(wyjWybor);
}

// Akcja przyciskow -----------------------------------------------------------------------
void Gra::start(){
    // Czyszczenie sceny
    scene->clear();
    drawRanking();
}

void Gra::rank(){
    // Czyszczenie sceny
    scene->clear();
    // Odpalanie rankingu
    //ranking = new Ranking();
    displayRank();
}

void Gra::back(){
    // Czyszczenie sceny
    scene->clear();
    displayMainMenu();
}

// Wyswietlenie menu rankingu ----------------------------------------------------------------
void Gra::displayRank(){
    // ranking
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Ranking"));
    QFont titleFont("times new roman",40);
    titleText->setFont(titleFont);

    // Ustawienie pozycji rankingu
    int fxPos = this->width()/2 - titleText->boundingRect().width()/2;
    int fyPos = 150;
    titleText->setPos(fxPos,fyPos);
    scene->addItem(titleText); //wstawienie

    // Przycisk powrot
    Wybor* powWybor = new Wybor(QString("Powrot"));
    int exPos = this->width()/2 - powWybor->boundingRect().width()/2;
    int eyPos = 425;
    powWybor->setPos(exPos,eyPos);
    connect(powWybor,SIGNAL(clicked()),this,SLOT(back()));
    scene->addItem(powWybor);
}

//Rozpoczeniecie gry///////////////////////////////////////////////////////////////////////////
//Ranking budowa
void Gra::drawTabela(int x, int y, int width, int height, QColor color, double opacity){
    QGraphicsRectItem* Tabela = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    Tabela->setBrush(brush);
    Tabela->setOpacity(opacity);
    scene->addItem(Tabela);
}

//Wyswietlanie rankingu
void Gra::drawRanking(){
    drawTabela(0,0,1024,40,Qt::darkGreen,1);

    //Liczba punktow
    ranking = new Ranking();
    int gxPos = 0;
    int gyPos = 0;
    ranking->setPos(gxPos,gyPos);
    scene->addItem(ranking);

    //Liczba zycia
    zdrowie = new Zdrowie();
    int hxPos = 120;
    int hyPos = 0;
    zdrowie->setPos(hxPos,hyPos);
    scene->addItem(zdrowie);

}

//Akcja gry
