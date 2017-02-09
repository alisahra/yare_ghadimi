#ifndef TWOWAYBG_H
#define TWOWAYBG_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class twoWayBg :public QObject,public QGraphicsPolygonItem {
    Q_OBJECT
public:
    twoWayBg();
public slots:
    void move();
private:
    static int randNum;
    static bool changeRandNum;
};


#endif // TWOWAYBG_H
