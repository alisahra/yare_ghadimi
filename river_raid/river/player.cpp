#include "player.h"
#include "shot.h"

#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>

void myPlayer::keyPressEvent(QKeyEvent *event)
{
    //qDebug() << "YeS";
    if(event->key() == Qt::Key_Left || event->key() == Qt::Key_A){
        setPos(x() - 10, y());
        qDebug() << "Going Left";
    }else if(event->key() == Qt::Key_Right || event->key() == Qt::Key_D){
        setPos(x() + 10, y());
        qDebug() << "Going Right";
    }else if(event->key() == Qt::Key_Space || event->key() == Qt::Key_W){
        // shot the enemy
        qDebug() << "Shot";
        shot * shoting = new shot();
        scene()->addItem(shoting);
    }
}
