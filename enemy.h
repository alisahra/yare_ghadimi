#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Enemy :public QObject,public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Enemy();
public slots:
    virtual void move()=0;
};

#endif // ENEMY_H
