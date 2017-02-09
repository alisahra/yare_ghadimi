#include "level.h"

Level::Level(int a)
{
    setLvl(a);
}

void Level::setLvl(int a)
{
    level = a;
}

void Level::incLvl()
{
    level++;
}

