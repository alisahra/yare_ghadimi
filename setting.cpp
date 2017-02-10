#include "setting.h"
#include "ui_setting.h"
#include "game.h"
#include <QFile>
#include <QTextStream>
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
    if(arg1 == "EASY") {

        QFile levelF("level.txt");
        levelF.open(QIODevice::WriteOnly);
        QTextStream out(&levelF);
        out << 0;
        levelF.close();

        game = new Game();
        game->show();
        this->close();
    }
    else if(arg1 == "MEDIUM") {

        QFile levelF("level.txt");
        levelF.open(QIODevice::WriteOnly);
        QTextStream out(&levelF);
        out << 5;
        levelF.close();

        game = new Game();
        game->show();
        this->close();
    }
    else if(arg1 == "HARD") {

        QFile levelF("level.txt");
        levelF.open(QIODevice::WriteOnly);
        QTextStream out(&levelF);
        out << 10;
        levelF.close();

        game = new Game();
        game->show();

        this->close();
    }
    else if(arg1 == "EXPERT") {

        QFile levelF("level.txt");
        levelF.open(QIODevice::WriteOnly);
        QTextStream out(&levelF);
        out << 20;
        levelF.close();

        game = new Game();
        game->show();

        this->close();
    }
}
