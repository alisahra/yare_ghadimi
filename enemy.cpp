#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>
#include <player.h>
#include "game.h"
#include <typeinfo>

extern Game * game;

Enemy::Enemy() {
    int randomPosition = rand() % 250;
    randomPosition += 250;

    //set random position
    setPos(randomPosition,0);
}
