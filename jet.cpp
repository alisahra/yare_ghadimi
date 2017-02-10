#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>
#include <player.h>
#include "game.h"
#include <typeinfo>
#include "jet.h"
#include <time.h>
#include <QFile>
#include <QTextStream>
extern Game * game;

Jet::Jet()
{
    time_t t1;
    srand((unsigned) time(&t1));
    int randomPosition = rand() % 300;
    randomPosition += 200;

    //set position
    setPos(0,randomPosition);

    // draw the enemy
    setPixmap(QPixmap(":/pic/Picture/jet.png"));

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

void Jet::move()
{
    setPos(x()+15-(speed/2),y()+speed);
    if(pos().y() > 800 || pos().x() > 800) {
        // decrease health
        //game->health->decrease();
        scene()->removeItem(this);
        delete this;
        qDebug() << "jet Deleted";
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
