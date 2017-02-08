#ifndef JET_H
#define JET_H
#include "enemy.h"

class Jet : public Enemy
{
public:
    Jet();
public slots:
    virtual void move();
};

#endif // JET_H
