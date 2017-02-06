#ifndef SHOT_H
#define SHOT_H

#include <QGraphicsRectItem>
#include <QObject>

class shot :public QObject,public QGraphicsRectItem {
    Q_OBJECT
public:
    shot();
public slots:
    void move();
};

#endif // SHOT_H
