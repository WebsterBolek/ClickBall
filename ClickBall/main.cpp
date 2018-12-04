#include "gra.h"
#include <QApplication>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>

void addValues(int id, QString nazwa, int wynik);

Gra* gra;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Precz z pseudolosowoscia
    qsrand(QDateTime::currentMSecsSinceEpoch() / 1000);
    qrand();

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
    else
    {
        qDebug()<<"Baza danych dziala";
    }

    //Tworzenie tabeli
    QString query = "CREATE TABLE tab ("
                    "ID integer,"
                    "NazwaGracza VARCHAR(20),"
                    "WynikGracza INT);";

    QSqlQuery qry;

    if(!qry.exec(query))
    {
        qDebug()<<"Tabela sie popsula";
    }
    else
    {
        qDebug()<<"Taleba dziala";
    }

    //addValues(1,"Nick",10);
    //Zamykanie bazy
    wyniki.close();
    //Baza danych koniec///////////////////////////////////////

    gra = new Gra();
    gra->show();
    // Przejscie do menu gry
    gra->displayMainMenu();

    return a.exec();
}


void addValues(int id, QString nazwa, int wynik)
{
    QSqlQuery qry;

    qry.prepare("INSERT INTO tab ("
                "ID,"
                "NazwaGracza,"
                "WynikGracza)"
                "VALUES (?,?,?);");

    qry.addBindValue(id);
    qry.addBindValue(nazwa);
    qry.addBindValue(wynik);

    if(!qry.exec())
    {
        qDebug()<<"Nie moge wpisac w tabele";
    }
}

