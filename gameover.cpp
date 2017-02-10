#include "gameover.h"
#include "ui_gameover.h"
#include "exit1.h"
#include "game.h"
extern Game * game;
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
    game->close();
    this->close();
}

void Gameover::on_pushButton_2_clicked()
{
    game->close();
    exit1 = new Exit1();
    exit1->show();
}
