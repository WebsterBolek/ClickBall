#include "dialog.h"
#include "ui_dialog.h"
#include "gra.h"
#include "ranking.h"
#include <QLabel>

extern int rankglobal;
extern Gra * gra;
extern Ranking * ranking;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    LiczbaPkt();
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
    gra->Baza();
    gra->displayMainMenu();
    delete this;
}

void Dialog::on_lineEdit_textEdited(const QString &arg1)
{
    nazwagracza = arg1;
}

void Dialog::LiczbaPkt()
{
    Number=rankglobal;
    ui->label_2->setText(QString::number(Number));
}

void Dialog::on_Dialog_rejected()
{
    gra->displayMainMenu();
    delete this;
}
