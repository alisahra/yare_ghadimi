#ifndef BRIDGE_H
#define BRIDGE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Bridge :public QObject,public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bridge();
public slots:
    void move();
private:
    int speed;
};

#endif // BRIDGE_H
