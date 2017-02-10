#include "bridge.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>
#include <player.h>
#include "game.h"
#include <typeinfo>
#include <ctime>
#include "twowaybg.h"
#include "thinbackground.h"
#include <QFile>
#include <QTextStream>
extern Game * game;

Bridge::Bridge()
{
        //set position
        setPos(scene()->width()/2,-200);

        // draw pic
        setPixmap(QPixmap(":/pic/Picture/bridge.png"));

        QFile levelF("level.txt");
        QTextStream in(&levelF);
        if(!levelF.open(QFile::ReadOnly)){
            qDebug() << "RIIIIIIIIIDDDDDDIIIIIIIII";
        }
        QString line = in.readAll();
        speed = line.toInt() + 3;
        //qDebug() << "speed is: " <<line;
        levelF.close();



        // connect time and shot
//        speed =  3 + (game->getSpeed() / 2);
        QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));

        // set timer
        timer->start(50);
}

void Bridge::move()
{
    setPos(x(),y()+speed);
    if(pos().y() > 700) {
        // decrease health
//        game->health->decrease();
        scene()->removeItem(this);
        delete this;
        qDebug() << "Bridge Deleted";
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
        if(typeid(*(collid_items[i])) == typeid(twoWayBg)/* || typeid(*(collid_items[i])) == typeid(thinBackGround)*/){
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
}
