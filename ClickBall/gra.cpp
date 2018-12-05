#include "gra.h"
#include "wybor.h"
#include "ranking.h"
#include "zdrowie.h"
#include "ball.h"
#include "ballukosna.h"
#include "dialog.h"
#include "dialogrank.h"
#include <QGraphicsTextItem>
#include <QGraphicsObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QtSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QtCore>
#include <QThread>
#include <QCoreApplication>

Dialogrank* dialogrank;

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
    QGraphicsTextItem* titleText2 = new QGraphicsTextItem(QString("Pelna wersja 1.0"));
    QFont titleFont2("Arial",14);
    titleText2->setFont(titleFont2);

    // Ustawienie pozycji wersji
    int bxPos = this->width()+6/2 - titleText->boundingRect().width()/2;
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
    Spawntimer = new QTimer(this);
    kulek = 0;
    gramy();
}

void Gra::rank(){
    // Odpalanie rankingu
    dialogrank = new Dialogrank();
    dialogrank->show();
}

void Gra::back(){
    // Czyszczenie sceny
    scene->clear();
    displayMainMenu();
}

//Rozpoczeniecie gry///////////////////////////////////////////////////////////////////////////
void Gra::gramy()
{
    drawRanking();
    QObject::connect(Spawntimer,SIGNAL(timeout()),this,SLOT(spawn()));
    Spawntimer->start(1000);
}
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
void Gra::spawn(){
    // Tworzy kule
    Ball * ball = new Ball();
    scene->addItem(ball);
    kulek +=1;
    if (kulek >= 5){
        if (kulek % 2 == 0)
        {
            Ballukosna * ballukosna = new Ballukosna();
            scene->addItem(ballukosna);
            if (kulek >= 15)
            {
                if (kulek % 2 == 0)
                {
                    Ballukosna * ballukosna2 = new Ballukosna();
                    scene->addItem(ballukosna2);
                }
            }
        }
    }
}

void Gra::Baza()
{
    //Baza danych//////////////////////////////////////////////////////
    qDebug()<<("Otwieranie bazy");

    //Tworzenie bazy danych
    QSqlDatabase wyniki;
    wyniki = QSqlDatabase::addDatabase("QSQLITE");
    wyniki.setDatabaseName("wyniki.sqlite");

    //Sprawdzanie czy sie udalo utworzyc
    if(!wyniki.open())
    {
        qDebug()<<"Baza danych sie popsula";
    }

    //Tworzenie tabeli
    QString query = "CREATE TABLE tab ("
                    "NazwaGracza VARCHAR(20),"
                    "WynikGracza INT);";

    QSqlQuery qry;

    if(!qry.exec(query))
    {
        qDebug()<<"Zapis";
    }

    if(zamkniecie == 1)
    {
        wyniki.close();
        qDebug()<<"Zamkniete";
    }

    //addValues(1,"Bolek",10);
    //Zamykanie bazy
    //wyniki.close();
    //Baza danych koniec///////////////////////////////////////
}

void Gra::addValues(QString nazwa, int wynik)
{
    QSqlQuery qry;

    qry.prepare("INSERT INTO tab ("
                "NazwaGracza,"
                "WynikGracza)"
                "VALUES (?,?);");

    qry.addBindValue(nazwa);
    qry.addBindValue(wynik);

    if(!qry.exec())
    {
        qDebug()<<"Nie moge wpisac w tabele";
    }
}
