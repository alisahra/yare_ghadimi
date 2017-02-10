#include "thinbackground.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>
#include "player.h"
#include "game.h"
#include "shot.h"
#include <typeinfo>
#include <QFile>
#include <QTextStream>
extern Game * game;

thinBackGround::thinBackGround(){

    QVector<QPointF> hexPoint;
    hexPoint << QPointF(0,-400) << QPointF(100,-500) << QPointF(300,-400) << QPointF(300,-200) << QPointF(100,-100) << QPointF(0,-200);
    QPolygonF hexagon(hexPoint);

    setPolygon(hexagon);
    setPen(QPen(Qt::darkGreen));
    setBrush(*new QBrush(Qt::darkGreen));

    // set position
//    setPos(0,-1000);

//    // draw the enemy
//    setRect(0,-1000,100+(24*l),800-(15*l));
//    setPen(QPen(Qt::darkGreen));
//    setBrush(*new QBrush(Qt::darkGreen));
    //scene->addRect(800-sideGrass,0,sideGrass,5,QPen(Qt::darkGreen),QBrush(Qt::darkGreen));
    // connect time and shot

    QFile levelF("level.txt");
    QTextStream in(&levelF);
    if(!levelF.open(QFile::ReadOnly)){
        qDebug() << "RIIIIIIIIIDDDDDDIIIIIIIII";
    }
    QString line = in.readAll();
    speed = line.toInt() + 3;
    //qDebug() << "speed is: " <<line;
    levelF.close();

    //speed =  3 + (game->getSpeed() / 2);
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // set timer
    timer->start(50);
}

thinBackGround::thinBackGround(int a){
    QVector<QPointF> hexPoint1;
    hexPoint1 << QPointF(700,-500) << QPointF(800,-400) << QPointF(800,-200) << QPointF(700,-100) << QPointF(500,-200) << QPointF(500,-400);
    QPolygonF hexagon1(hexPoint1);

    setPolygon(hexagon1);
    setPen(QPen(Qt::darkGreen));
    setBrush(*new QBrush(Qt::darkGreen));


    // set position
//    setPos(0,-1000);

    // draw the enemy
//    setRect(700-(24*l),-1000,100+(24*l),800-(15*l));
//    setPen(QPen(Qt::darkGreen));
//    setBrush(*new QBrush(Qt::darkGreen));
    //scene()->addRect(800-sideGrass,0,sideGrass,5,QPen(Qt::darkGreen),QBrush(Qt::darkGreen));
    // connect time and shot

    QFile levelF("level.txt");
    QTextStream in(&levelF);
    if(!levelF.open(QFile::ReadOnly)){
        qDebug() << "RIIIIIIIIIDDDDDDIIIIIIIII";
    }
    QString line = in.readAll();
    speed = line.toInt() + 3;
    //qDebug() << "speed is: " <<line;
    levelF.close();

    //    speed =  3 + (game->getSpeed() / 2);
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // set timer
    timer->start(50);
}

void thinBackGround::move()
{
    setPos(x(),y()+speed);
    if(pos().y() > 1300) {
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
            qDebug() << "Game Over!!";
            return;
        }
    }
}
