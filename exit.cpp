#include "exit.h"
#include "ui_exit.h"
#include "game.h"
#include "menu.h"
#include "puasepage.h"
extern PuasePage * puasePage;
extern Menu* menu;
extern Game * game;
Exit::Exit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Exit)
{
    ui->setupUi(this);
}

Exit::~Exit()
{
    delete ui;
}

void Exit::on_pushButton_clicked()
{
    this->close();
    puasePage->close();
    game->close();
    menu->close();
}
