#include "gra.h"
#include <QApplication>
#include <QtSql>

Gra* gra;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    gra = new Gra();
    gra->show();
    // Przejscie do wyboru gry
    gra->displayMainMenu();

    return a.exec();
}
