#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>


Enemy::Enemy()
{
    int randomPosition = rand() % 250;
    randomPosition += 250;

    //set random position
    setPos(randomPosition,0);

    // draw the enemy
    setRect(0,0,50,100);

    // connect time and shot
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // set timer
    timer->start(50);
}

void Enemy::move()
{
    setPos(x(),y()+5);
    if(pos().y() > 650){
        scene()->removeItem(this);
        delete this;
        qDebug() << "Enemy Deleted";
        return;
    }
}
