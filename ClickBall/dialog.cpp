#include "dialog.h"
#include "ui_dialog.h"
#include "gra.h"
#include "ranking.h"

extern int rankglobal;
extern Gra * gra;
extern Ranking * ranking;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    gra->zamkniecie=0;
    a=rankglobal;
    gra->Baza();
    gra->addValues(nazwagracza,a);
    gra->zamkniecie=1;
    gra->displayMainMenu();
    delete this;
}

void Dialog::on_lineEdit_textEdited(const QString &arg1)
{
    nazwagracza = arg1;
}
