#include "certain.h"
#include "ui_certain.h"
#include "menu.h"
#include "game.h"

extern Game * game;
extern Menu * menu;
Certain::Certain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Certain)
{
    ui->setupUi(this);
}

Certain::~Certain()
{
    delete ui;
}

void Certain::on_pushButton_2_clicked()
{
    this->close();
}

void Certain::on_pushButton_clicked()
{
    game->close();
    menu->close();
    this->close();
}
