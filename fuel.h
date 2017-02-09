#ifndef FUEL_H
#define FUEL_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
class Fuel:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Fuel(int mov);
public slots:
    void move();
};

#endif // FUEL_H
