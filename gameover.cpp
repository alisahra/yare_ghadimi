#include "gameover.h"
#include "ui_gameover.h"
#include "exit1.h"
Exit1 * exit1;
Gameover::Gameover(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gameover)
{
    ui->setupUi(this);
}

Gameover::~Gameover()
{
    delete ui;
}

void Gameover::on_pushButton_clicked()
{
    this->close();
}

void Gameover::on_pushButton_2_clicked()
{
    exit1 = new Exit1();
    exit1->show();
}
