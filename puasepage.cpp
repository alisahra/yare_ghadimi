#include "puasepage.h"
#include "ui_puasepage.h"
#include "buy.h"
#include "game.h"
#include "exit.h"
extern Game * game;
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

void PuasePage::on_pushButton_2_clicked()
{
    Buy * buy = new Buy();
    buy->show();
}

void PuasePage::on_pushButton_3_clicked()
{
    Exit * exit = new exit();
    exit->show();
}
