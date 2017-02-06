#include "player.h"
#include "shot.h"
#include "enemy.h"

#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>

void myPlayer::keyPressEvent(QKeyEvent *event)
{
    //qDebug() << "YeS";
    if(event->key() == Qt::Key_Left || event->key() == Qt::Key_A){
        if(pos().x() > 0){
            setPos(x() - 10, y());
            qDebug() << "Going Left";
        }
    }else if(event->key() == Qt::Key_Right || event->key() == Qt::Key_D){
        if(pos().x() + this->rect().width() < scene()->width()){
            setPos(x() + 10, y());
            qDebug() << "Going Right";
        }
    }else if(event->key() == Qt::Key_Space || event->key() == Qt::Key_W){
        // shot the enemy
        qDebug() << "Shot";
        shot * shoting = new shot();
        shoting->setPos(x() + this->rect().width()/2 - 1 ,y());
        scene()->addItem(shoting);
    }
}

void myPlayer::spawn()
{
    // create enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
