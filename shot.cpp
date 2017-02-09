#include "shot.h"
#include <QTimer>
#include "player.h"
#include <QGraphicsScene>
#include <QDebug>
#include "enemy.h"
#include <typeinfo>
#include "score.h"
#include "game.h"
#include "helicopter.h"
#include "ship.h"
#include "jet.h"
#include "fuel.h"
#include "thinbackground.h"
#include "twowaybg.h"
extern Game * game;

shot::shot(QGraphicsItem * parent) : QObject(), QGraphicsRectItem(parent) {
    game->setSingelton(false);
    // draw the player
    setRect(0,0,5,7);
    setPen(QPen(Qt::yellow));
    setBrush(*new QBrush(Qt::yellow));
    // connect player and shot
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // set timer
    timer->start(25);
}

void shot::move()
{
    setPos(x(),y()-20);
    if(pos().y() + rect().height() < -5) {
        scene()->removeItem(this);
        game->setSingelton(true);
        delete this;
        qDebug() << "Shot Deleted";
        return;
    }

    // check if any enemy is down
    QList<QGraphicsItem *> collid_items = collidingItems();
    for(int i = 0, n = collid_items.size(); i < n; i++) {
        int collid = 0;
        if(typeid(*(collid_items[i])) == typeid(Ship)){game->score->increase(30); collid++;}
        else if(typeid(*(collid_items[i])) == typeid(Helicopter)){game->score->increase(60); collid++;}
        else if(typeid(*(collid_items[i])) == typeid(Fuel)){game->score->increase(80); collid++;} //|| typeid(*(collid_items[i])) == typeid(Helicopter) || typeid(*(collid_items[i])) == typeid(Jet) || typeid(*(collid_items[i])) == typeid(Ship)) {
        else if(typeid(*(collid_items[i])) == typeid(Jet)){game->score->increase(100); collid++;}
        else if(typeid(*(collid_items[i])) == typeid(twoWayBg))
        {
            scene()->removeItem(this);
            game->setSingelton(true);
            delete this;
            qDebug()<<"Shot deleted!";
            return;
        }
        else if(typeid(*(collid_items[i])) == typeid(thinBackGround))
        {
            scene()->removeItem(this);
            game->setSingelton(true);
            delete this;
            qDebug()<<"Shot deleted!";
            return;
        }
        // remove
        if(collid ){
            game->setSingelton(true);
            scene()->removeItem(collid_items[i]);
            scene()->removeItem(this);
            delete collid_items[i];
            delete this;
            qDebug() << "Object is down!!";
            return;
        }
    }
}
