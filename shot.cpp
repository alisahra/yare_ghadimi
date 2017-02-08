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

extern Game * game;

shot::shot(QGraphicsItem * parent) : QObject(), QGraphicsRectItem(parent) {
    // draw the player
    setRect(0,0,5,7);
    setPen(QPen(Qt::yellow));
    setBrush(*new QBrush(Qt::yellow));
    // connect player and shot
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // set timer
    timer->start(50);
}

void shot::move()
{
    setPos(x(),y()-10);
    if(pos().y() + rect().height() < -5) {
        scene()->removeItem(this);
        delete this;
        qDebug() << "Shot Deleted";
        return;
    }

    // check if any enemy is down
    QList<QGraphicsItem *> collid_items = collidingItems();
    for(int i = 0, n = collid_items.size(); i < n; i++) {
        if(typeid(*(collid_items[i])) == typeid(Helicopter) || typeid(*(collid_items[i])) == typeid(Jet) || typeid(*(collid_items[i])) == typeid(Ship)) {
            // increase score
            game->score->increase();

            // remove
            scene()->removeItem(collid_items[i]);
            scene()->removeItem(this);
            delete collid_items[i];
            delete this;
            qDebug() << "enemy is down!!";
            return;
        }
    }
}