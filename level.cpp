#include "level.h"
#include <QDebug>
#include <QFile>

Level::Level(int a)
{
    level = a;
    qDebug() << level;
}

void Level::setLvl(int a){
    level = a;
    if(level <= 20){
        speed->setSpeed(a);
    }else if(level > 20){
        speed->setSpeed(20);
    }
}

void Level::incLvl()
{
    level++;
    qDebug() << "Level increased";
    if(level <= 20){
        speed->setSpeed(level);
        qDebug() << "Speed increased";
        qDebug() << level;
    }
    QFile levelF("level.txt");
    levelF.open(QIODevice::WriteOnly);
    QTextStream out(&levelF);
    out << level;
    levelF.close();
}

int Level::getSpeed(){
    return speed->getSpeed();
}

int Level::getLevel(){
    return level;
}
