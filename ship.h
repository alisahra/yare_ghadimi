#ifndef SHIP_H
#define SHIP_H
#include "enemy.h"

class Ship : public Enemy
{
public:
    Ship();
public slots:
    virtual void move();

private:
    int speed;
};

#endif // SHIP_H
