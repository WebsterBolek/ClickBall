#include "dialogrank.h"
#include "ui_dialogrank.h"
#include "gra.h"
#include <QtSql>
#include <QSqlDatabase>

extern Gra * gra;

Dialogrank::Dialogrank(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogrank)
{
    ui->setupUi(this);
    wyniki = QSqlDatabase::addDatabase("QSQLITE");
    wyniki.setDatabaseName("wyniki.sqlite");
    wyniki.open();

    wys = new QSqlTableModel(this);
    wys->setTable("tab");
    wys->select();

    ui->tableView->setModel(wys);
}

Dialogrank::~Dialogrank()
{
    delete ui;
}

void Dialogrank::on_pushButton_clicked()
{
    delete this;
    wyniki.close();
}
