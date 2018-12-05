#include "gra.h"
#include <QApplication>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QtCore>
#include <QThread>
#include <QCoreApplication>

Gra* gra;

// Klasa watki
class Worker : public QObject
{
    Q_OBJECT
private slots:
    void onTimeout()
    {
        qDebug()<<QThread::currentThreadId();
    }
};

class Thread : public QThread
{
    Q_OBJECT

private:
    void run()
    {
        qDebug()<<currentThreadId();
        QTimer timer;
        Worker worker;
        connect(&timer, SIGNAL(timeout()), &worker, SLOT(onTimeout()));
        timer.start(1000);

        exec();
    }
};
//Watki//////////////////////

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
