#ifndef FUEL_H
#define FUEL_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
class Fuel:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Fuel();
public slots:
    void move();
private:
    int speed;
};

#endif // FUEL_H
