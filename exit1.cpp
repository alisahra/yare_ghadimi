#include "exit1.h"
#include "ui_exit1.h"
#include"game.h"
#include "menu.h"
#include "puasepage.h"
#include "gameover.h"
extern Menu * menu;
extern Gameover * gameover;
Exit1::Exit1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Exit1)
{
    ui->setupUi(this);
}

Exit1::~Exit1()
{
    delete ui;
}

void Exit1::on_pushButton_clicked()
{
    this->close();
}

void Exit1::on_pushButton_2_clicked()
{
    this->close();
    gameover->close();
    menu->close();
}
