#ifndef DIALOGRANK_H
#define DIALOGRANK_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>

namespace Ui {
class Dialogrank;
}

class Dialogrank : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogrank(QWidget *parent = nullptr);
    ~Dialogrank();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialogrank *ui;
    QSqlDatabase wyniki;
    QSqlTableModel *wys;
};

#endif // DIALOGRANK_H
