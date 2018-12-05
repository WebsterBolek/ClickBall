#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    QString nazwagracza;
    int a;

private slots:
    void on_pushButton_clicked();
    void on_lineEdit_textEdited(const QString &arg1);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
