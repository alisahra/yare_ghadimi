#ifndef HEALTH_H
#define HEALTH_H


#include <QGraphicsTextItem>
#include <QObject>
#include <QGraphicsPixmapItem>

class Health: public QGraphicsTextItem{
    Q_OBJECT
private:
    int health;
public:
    Health(QGraphicsItem * parent=0);
    void increase();
    int getHealth();
public slots:
    void decrease();
    void fuelSpawn();
};


#endif // HEALTH_H
