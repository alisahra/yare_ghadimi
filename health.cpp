#include "health.h"
#include <QFont>
#include "fuel.h"
#include "game.h"

extern Game * game;

Health::Health(QGraphicsItem *parent) : QGraphicsTextItem (parent) {
    // initialize score
    health = 700;

    // draw score
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",20));
}

void Health::increase()
{
    if(health < 696){
        health += 4;
        healthIncreased(getHealth());
        // draw score
        setPlainText(QString("Health: ") + QString::number(health));
    }else if(health < 700){
        health = 700;
        // draw score
        setPlainText(QString("Health: ") + QString::number(health));
    }
}

void Health::decrease()
{
    health--;
    setPlainText(QString("Health: ") + QString::number(health));
    if(health < 0){
        game->gameOver();
    }
}

void Health::fuelSpawn()
{
    Fuel * fuel = new Fuel();
    scene()->addItem(fuel);
}

int Health::getHealth()
{
    return health;
}
