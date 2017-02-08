#ifndef SHOT_H
#define SHOT_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>

class shot :public QObject,public QGraphicsRectItem {
    Q_OBJECT
public:
    shot(QGraphicsItem * parent=0);
public slots:
    void move();
};

#endif // SHOT_H
