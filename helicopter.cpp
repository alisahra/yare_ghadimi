#include "helicopter.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>
#include <player.h>
#include "game.h"
#include <typeinfo>
#include <ctime>

extern Game * game;

Helicopter::Helicopter(int mov) {
    if(mov == 0){
        time_t t1;
        srand((unsigned) time(&t1));
        int randomPosition = rand() % 500;
        randomPosition += 100;

        //set random position
        setPos(randomPosition,0);

        // draw pic
        setPixmap(QPixmap(":/pic/Picture/heli.png"));

        // connect time and shot
        QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));

        // set timer
        timer->start(50);
    }else if(mov == 1){
        setPos(375,0);

        // draw pic
        setPixmap(QPixmap(":/pic/Picture/heli.png"));

        // connect time and shot
        QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));

        // set timer
        timer->start(50);

    }else if(mov == 2){
        time_t t1;
        srand((unsigned) time(&t1));
        int randomPosition = rand() % 200;
        if(randomPosition < 100){
            randomPosition += 100;
        }else if(randomPosition >= 100){
            randomPosition += 400;
        }

        //set random position
        setPos(randomPosition,0);

        // draw pic
        setPixmap(QPixmap(":/pic/Picture/heli.png"));

        // connect time and shot
        QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));

        // set timer
        timer->start(50);
    }
}

void Helicopter::move()
{
    setPos(x(),y()+5);
    if(pos().y() > 700) {
        // decrease health
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
        qDebug() << "Helicopter Deleted";
        return;
    }

    QList<QGraphicsItem *> collid_items = collidingItems();
    for(int i = 0, n = collid_items.size(); i < n; i++){
        if(typeid(*(collid_items[i])) == typeid(myPlayer)) {
            // remove
            scene()->removeItem(collid_items[i]);
            scene()->removeItem(this);
            delete collid_items[i];
            delete this;
            qDebug() << "Game Over!!";
            return;
        }
    }
}
