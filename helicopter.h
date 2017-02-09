#ifndef HELICOPTER_H
#define HELICOPTER_H
#include "enemy.h"

class Helicopter : public Enemy{
public:
    Helicopter(int mov);
public slots:
    virtual void move();
};

#endif // HELICOPTER_H
