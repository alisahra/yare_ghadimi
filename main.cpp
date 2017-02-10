#include "player.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include "game.h"
#include "menu.h"
#include "health.h"
#include "gameover.h"

Game * game;
Menu * menu;
Gameover * gameOver;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    menu = new Menu();
    menu->setWindowTitle("RIVER RAID");
    menu->show();

    return a.exec();
}
