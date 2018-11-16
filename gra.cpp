#include "gra.h"
#include "wybor.h"
#include "akcja.h"
#include "ranking.h"
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
    // Odpalanie nowej gry
    akcja = new Akcja();
    displayAkcja();
}

void Gra::rank(){
    // Czyszczenie sceny
    scene->clear();
    // Odpalanie rankingu
    ranking = new Ranking();
    displayRank();
}

void Gra::back(){
    // Czyszczenie sceny
    scene->clear();
    displayMainMenu();
}

// Wyswietlenie rankingu ----------------------------------------------------------------
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

// Wyswietlenie akcji ------------------------------------------------------------
void Gra::displayAkcja(){
    // Akcja
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Akcja"));
    QFont titleFont("times new roman",40);
    titleText->setFont(titleFont);

    // Ustawienie pozycji akcja
    int fxPos = this->width()/2 - titleText->boundingRect().width()/2;
    int fyPos = 150;
    titleText->setPos(fxPos,fyPos);
    scene->addItem(titleText); //wstawienie
}
