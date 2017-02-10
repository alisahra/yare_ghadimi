#ifndef THINBACKGROUND_H
#define THINBACKGROUND_H

#include <QGraphicsPolygonItem>
#include <QObject>
#include <QGraphicsItem>

class thinBackGround :public QObject,public QGraphicsPolygonItem {
    Q_OBJECT
public:
    thinBackGround();
    thinBackGround(int a);
public slots:
    void move();
private:
    int speed;
};

#endif // THINBACKGROUND_H
