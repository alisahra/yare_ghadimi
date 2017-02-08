#include "twowaybg.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>
#include "player.h"
#include "game.h"
#include "shot.h"
#include <typeinfo>

twoWayBg::twoWayBg()
{
    // set position
    setPos(0,-100);

    // draw the enemy
    setRect(100,-1000,200,1000);
    setPen(QPen(Qt::darkGreen));
    setBrush(QBrush(Qt::darkGreen));
    //scene->addRect(800-sideGrass,0,sideGrass,5,QPen(Qt::darkGreen),QBrush(Qt::darkGreen));
    // connect time and shot
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // set timer
    timer->start(50);
}

void twoWayBg::move()
{
    setPos(x(),y()+5);
    if(pos().y() > 800) {
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
