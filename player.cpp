#include "player.h"
#include "shot.h"
#include "enemy.h"
#include "background.h"
#include "strightbackground.h"
#include "thinbackground.h"
#include "twowaybg.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "ship.h"
#include "helicopter.h"
#include "jet.h"
#include <ctime>
#include "game.h"
#include "fuel.h"
#include <QWidget>
#include "puasepage.h"

extern Game * game;
myPlayer::myPlayer(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
    setPixmap(QPixmap(":/pic/Picture/raider.png"));
}

void myPlayer::keyPressEvent(QKeyEvent *event)
{
    //qDebug() << "YeS";
    if(event->key() == Qt::Key_Left || event->key() == Qt::Key_A)
    {
        if(pos().x() > 0){
            setPixmap(QPixmap(":/pic/Picture/raider_mv.png"));
            setPos(x() - 15, y());
            qDebug() << "Going Left";
        }
    }
    else if(event->key() == Qt::Key_Right || event->key() == Qt::Key_D)
    {
        if(pos().x() + this->pixmap().width() < scene()->width()){
            setPixmap(QPixmap(":/pic/Picture/raider_mv.png"));
            setPos(x() + 15, y());
            qDebug() << "Going Right";
        }
    }
    else if((event->key() == Qt::Key_Space || event->key() == Qt::Key_W) && game->getSingelton())
    {
        // shot the enemy
        qDebug() << "Shot";
        shot * shoting = new shot();
        shoting->setPos(x() + this->pixmap().width()/2 - 1 ,y());
        scene()->addItem(shoting);
    }
    else if((event->key() == Qt::Key_Escape))
    {
        game->gamePuase();
    }
    else
    {
        setPixmap(QPixmap(":/pic/Picture/raider.png"));
    }
}

void myPlayer::objectSpawn()
{
    setPixmap(QPixmap(":/pic/Picture/raider.png"));
    // create enemy
    time_t t;
    srand((unsigned) time(&t));
    int rnd = rand() % 16;

    if (rnd == 0 || rnd == 3 || rnd == 5  || rnd == 6 || rnd == 7){
        Ship * ship = new Ship();
        scene()->addItem(ship);
    }
    else if (rnd == 1 || rnd == 4 || rnd == 8 || rnd == 9){
        Helicopter * helicopter = new Helicopter();
        scene()->addItem(helicopter);
    }
    else if(rnd == 2){
        Jet * jet = new Jet();
        scene()->addItem(jet);
    }
    else if(rnd == 10 || rnd == 11 || rnd == 12 || rnd == 13 || rnd == 14 || rnd == 15)
    {
        Fuel * fuel = new Fuel();
        scene()->addItem(fuel);
    }
}

void myPlayer::thinBgLSpawn()
{
    thinBackGround * item = new thinBackGround();
    scene()->addItem(item);
}

void myPlayer::thinBgRSpawn()
{
    thinBackGround * item = new thinBackGround(1);
    scene()->addItem(item);
}

void myPlayer::settingPixmap()
{
    setPixmap(QPixmap(":/pic/Picture/raider.png"));
}

void myPlayer::twoWaysBgSpawn()
{
    twoWayBg * item = new twoWayBg();
    scene()->addItem(item);
}
