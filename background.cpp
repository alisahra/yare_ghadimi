#include "background.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>
#include "player.h"
#include "game.h"
#include "shot.h"
#include <typeinfo>

extern Game * game;

BackGround::BackGround()
{
    // set position
    setPos(0,0);

    // draw the enemy
    setRect(0,-5,100,610);
    setPen(QPen(Qt::darkGreen));
    setBrush(*new QBrush(Qt::darkGreen));
    //scene->addRect(800-sideGrass,0,sideGrass,5,QPen(Qt::darkGreen),QBrush(Qt::darkGreen));
    // connect time and shot
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

BackGround::BackGround(int a) {
    // set position
    setPos(0,0);

    // draw the enemy
    setRect(700,0,100,610);
    setPen(QPen(Qt::darkGreen));
    setBrush(*new QBrush(Qt::darkGreen));

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(checkColl()));
    timer->start(50);
}

void BackGround::checkColl()
{
    QList<QGraphicsItem *> collid_items = collidingItems();
    for(int i = 0, n = collid_items.size(); i < n; i++){
        if((typeid(*(collid_items[i])) == typeid(myPlayer)) || (typeid(*(collid_items[i])) == typeid(shot))) {
            // remove
            scene()->removeItem(collid_items[i]);
            delete collid_items[i];
            return;
        }
    }
}
