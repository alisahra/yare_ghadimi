#include "puasepage.h"
#include "ui_puasepage.h"
#include "buy.h"
#include "game.h"
#include "exit.h"
extern Game * game;
extern Exit * exit;
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
    exit = new Exit();
    exit->show();
}

