#include "puasepage.h"
#include "ui_puasepage.h"
#include "buy.h"
#include "game.h"
#include "exit.h"
#include "certain.h"
extern Game * game;
//Exit * e;
PuasePage::PuasePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PuasePage)
{
    ui->setupUi(this);
}

PuasePage::~PuasePage()
{
    delete ui;
}

//void PuasePage::on_pushButton_2_clicked()
//{
//    Buy * buy = new Buy();
//    buy->show();
//}

//void PuasePage::on_pushButton_3_clicked()
//{
//    exit = new Exit();
//    exit->show();
//}


void PuasePage::on_pushButton_2_clicked()
{
    Buy * buy = new Buy();
    buy->show();
}

void PuasePage::on_pushButton_3_clicked()
{
    Certain * a = new Certain();
    a->show();

//    this->close();
//    game->close();

}
