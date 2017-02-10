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
    health += 3;
    healthIncreased(getHealth());
    // draw score
    setPlainText(QString("Health: ") + QString::number(health));
}

void Health::decrease()
{
    health--;
    setPlainText(QString("Health: ") + QString::number(health));
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
