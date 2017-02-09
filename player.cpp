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

void myPlayer::objectSpawn(int mov)
{
    // create enemy
    time_t t;
    srand((unsigned) time(&t));
    int rnd = rand() % 4;

    if (rnd == 0){
        Ship * ship = new Ship(mov);
        scene()->addItem(ship);
    }
    else if (rnd == 1){
        Helicopter * helicopter = new Helicopter(mov);
        scene()->addItem(helicopter);
    }
    else if(rnd == 2){
        Jet * jet = new Jet();
        scene()->addItem(jet);
    }
    else if(rnd == 3)
    {
        Fuel * fuel = new Fuel(mov);
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

void myPlayer::twoWaysBgSpawn()
{
    twoWayBg * item = new twoWayBg();
    scene()->addItem(item);
}

