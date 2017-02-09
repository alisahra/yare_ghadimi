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

extern Game * game;
myPlayer::myPlayer(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
    setPixmap(QPixmap(":/pic/Picture/raider.png"));
}

void myPlayer::keyPressEvent(QKeyEvent *event)
{
    //qDebug() << "YeS";
    if(event->key() == Qt::Key_Left || event->key() == Qt::Key_A){
        if(pos().x() > 0){
            setPos(x() - 10, y());
            qDebug() << "Going Left";
        }
    }else if(event->key() == Qt::Key_Right || event->key() == Qt::Key_D){
        if(pos().x() + this->pixmap().width() < scene()->width()){
            setPos(x() + 10, y());
            qDebug() << "Going Right";
        }
    }else if((event->key() == Qt::Key_Space || event->key() == Qt::Key_W) && game->getSingelton()){
        // shot the enemy
        qDebug() << "Shot";
        shot * shoting = new shot();
        shoting->setPos(x() + this->pixmap().width()/2 - 1 ,y());
        scene()->addItem(shoting);
    }
}

void myPlayer::objectSpawn()
{
    // create enemy
    time_t t;
    srand((unsigned) time(&t));
    int rnd = rand() % 4;

    if (rnd == 0){
        Ship * ship = new Ship(0);
        scene()->addItem(ship);
    }
    else if (rnd == 1){
        Helicopter * helicopter = new Helicopter(0);
        scene()->addItem(helicopter);
    }
    else if(rnd == 2){
        Jet * jet = new Jet();
        scene()->addItem(jet);
    }
    else if(rnd == 3)
    {
        Fuel * fuel = new Fuel(0);
        scene()->addItem(fuel);
    }
}

void myPlayer::thinBgLSpawn()
{
    QVector<thinBackGround *> Litems;
    Litems.resize(11);
    for(int i = 0; i <= 10; i++) {
        Litems[i] = new thinBackGround(i);
        scene()->addItem(Litems[i]);
    }
}

void myPlayer::thinBgRSpawn()
{
    QVector<thinBackGround *> Ritems;
    Ritems.resize(11);
    for(int i = 0; i <= 10; i++) {
        Ritems[i] = new thinBackGround(i,0);
        scene()->addItem(Ritems[i]);
    }
}

void myPlayer::bgSwapn()
{
    time_t t;
    srand((unsigned) time(&t));
    int rnd = rand() % 3;

    if(rnd == 0){
        // create enemy normally

    }else if(rnd == 1){
        // create thin bg and create enemy base on it
    }else if(rnd == 2){
        // create two ways bg and create enemy base on it
    }
}

void myPlayer::twoWaysBgSpawn()
{
    twoWayBg * item = new twoWayBg();
    scene()->addItem(item);
}

//void myPlayer::objectSpawn1()
//{
//    // create enemy
//    time_t t;
//    srand((unsigned) time(&t));
//    int rnd = rand() % 4;

//    if (rnd == 0){
//        Ship * ship = new Ship(1);
//        scene()->addItem(ship);
//    }
//    else if (rnd == 1){
//        Helicopter * helicopter = new Helicopter(1);
//        scene()->addItem(helicopter);
//    }
//    else if(rnd == 2){
//        Jet * jet = new Jet();
//        scene()->addItem(jet);
//    }
//    else if(rnd == 3)
//    {
//        Fuel * fuel = new Fuel(1);
//        scene()->addItem(fuel);
//    }
//}

//void myPlayer::objectSpawn2()
//{
//    // create enemy
//    time_t t;
//    srand((unsigned) time(&t));
//    int rnd = rand() % 4;

//    if (rnd == 0){
//        Ship * ship = new Ship(2);
//        scene()->addItem(ship);
//    }
//    else if (rnd == 1){
//        Helicopter * helicopter = new Helicopter(2);
//        scene()->addItem(helicopter);
//    }
//    else if(rnd == 2){
//        Jet * jet = new Jet();
//        scene()->addItem(jet);
//    }
//    else if(rnd == 3)
//    {
//        Fuel * fuel = new Fuel(2);
//        scene()->addItem(fuel);
//    }
//}

