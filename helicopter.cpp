#include "helicopter.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>
#include <player.h>
#include "game.h"
#include <typeinfo>
#include <ctime>
#include "thinbackground.h"
#include "twowaybg.h"
#include <QFile>
#include <QTextStream>

extern Game * game;

Helicopter::Helicopter() {
        time_t t1;
        srand((unsigned) time(&t1));
        int randomPosition = rand() % 500;
        randomPosition += 100;

        //set random position
        setPos(randomPosition,-200);

        // draw pic
        setPixmap(QPixmap(":/pic/Picture/heli.png"));

        // connect time and shot

        QFile levelF("level.txt");
        QTextStream in(&levelF);
        QString line = in.readLine();
        speed = (line.toInt()/2) + 3;
        levelF.close();


        //speed =  3 + (game->getSpeed() / 2);
        QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));

        // set timer
        timer->start(50);

}

void Helicopter::move()
{
    setPos(x(),y()+speed);
    if(pos().y() > 700) {
        // decrease health
        //game->health->decrease();
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
        if(typeid(*(collid_items[i])) == typeid(twoWayBg) || typeid(*(collid_items[i])) == typeid(thinBackGround)){
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
}
