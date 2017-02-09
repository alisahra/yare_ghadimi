#include "health.h"
#include <QFont>



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

    // draw score
    setPlainText(QString("Health: ") + QString::number(health));
}

void Health::decrease()
{
    health--;
    setPlainText(QString("Health: ") + QString::number(health));
}

int Health::getHealth()
{
    return health;
}
