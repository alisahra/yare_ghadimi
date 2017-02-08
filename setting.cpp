#include "setting.h"
#include "ui_setting.h"
#include "game.h"
extern Game * game;
Setting::Setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);
}

Setting::~Setting()
{
    delete ui;
}

void Setting::on_comboBox_activated(const QString &arg1)
{
    if(arg1 == "EASY")
    {
        game = new Game();
        game->show();
        this->close();
    }
    else if(arg1 == "MEDIUM")
    {
        game = new Game();
        game->show();
        this->close();
    }
    else if(arg1 == "HARD")
    {
        game = new Game();
        game->show();
        this->close();
    }
    else if(arg1 == "EXPERT")
    {
        game = new Game();
        game->show();
        this->close();
    }
}
