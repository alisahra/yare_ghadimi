#include "rect.h"
#include <QPen>
#include <QBrush>

Rect::Rect()
{
    // set position
    setPos(0,0);

    // draw the enemy
    setRect(0,560,800,40);
    setPen(QPen(Qt::gray));
    setBrush(*new QBrush(Qt::gray));
    setZValue(1000);
}

