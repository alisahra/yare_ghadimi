#include "strightbackground.h"
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

StrightBackGround::StrightBackGround()
{
    // set position
    setPos(0,-100);

    // draw the enemy
    setRect(0,-100,(game->scene->width()/2) - 300,100);
    setPen(QPen(Qt::darkGreen));
    setBrush(*new QBrush(Qt::darkGreen));
    //scene->addRect(800-sideGrass,0,sideGrass,5,QPen(Qt::darkGreen),QBrush(Qt::darkGreen));
    // connect time and shot
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // set timer
    timer->start(50);
}

StrightBackGround::StrightBackGround(int a) {
    // set position
    setPos(0,-100);

    // draw the enemy
    setRect((game->scene->width()/2) + 300,-100,(game->scene->width()/2) - 300,100);
    setPen(QPen(Qt::darkGreen));
    setBrush(*new QBrush(Qt::darkGreen));
    //scene()->addRect(800-sideGrass,0,sideGrass,5,QPen(Qt::darkGreen),QBrush(Qt::darkGreen));
    // connect time and shot
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // set timer
    timer->start(50);
}

void StrightBackGround::move()
{
    setPos(x(),y()+5);
    if(pos().y() > game->scene->height() + 400) {
        // decrease health
        scene()->removeItem(this);
        delete this;
        return;
    }

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
