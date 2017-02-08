#include "speed.h"

Speed::Speed()
{
    speed = 0;
}

Speed::Speed(int a)
{
    setSpeed(a);
}

int Speed::getSpeed()
{
    return speed;
}

void Speed::setSpeed(int a)
{
    speed = a;
}

void Speed::increaseSpeed(int a)
{
    speed += a;
}
